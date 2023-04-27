/**
 * @file schnorr_bcrypto_410.c
 * @author Krisna Pranav
 * @brief schnorr bcrypto 410
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */


#include "schnorr_bcrypto_410.h"

#include <stdint.h>
#include <string.h>

#include <os.h>
#include <cx.h>

#include "src/consts.h"
#include "utils/util.h"

static unsigned char const SECP256K1_G[] = {
    0x79, 0xbe, 0x66, 0x7e, 0xf9, 0xdc, 0xbb, 0xac,
    0x55, 0xa0, 0x62, 0x95, 0xce, 0x87, 0x0b, 0x07,
    0x02, 0x9b, 0xfc, 0xdb, 0x2d, 0xce, 0x28, 0xd9,
    0x59, 0xf2, 0x81, 0x5b, 0x16, 0xf8, 0x17, 0x98,
    0x48, 0x3a, 0xda, 0x77, 0x26, 0xa3, 0xc4, 0x65,
    0x5d, 0xa4, 0xfb, 0xfc, 0x0e, 0x11, 0x08, 0xa8,
    0xfd, 0x17, 0xb4, 0x48, 0xa6, 0x85, 0x54, 0x19,
    0x9c, 0x47, 0xd0, 0x8f, 0xfb, 0x10, 0xd4, 0xb8 };

static unsigned char const SECP256K1_N[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0xba, 0xae, 0xdc, 0xe6, 0xaf, 0x48, 0xa0, 0x3b,
    0xbf, 0xd2, 0x5e, 0x8c, 0xd0, 0x36, 0x41, 0x41 };

static  unsigned char const SECP256K1_P []  = { 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfc, 0x2f };

static unsigned char const SECP256K1_ONE[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };

static unsigned char const SECP256K1_RES_EXP[] = {
    0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFE, 0x17 };


/**
 * @brief hasQuadY
 * 
 * @param point 
 * @return int 
 */
static int hasQuadY(const uint8_t *point) {
    unsigned WIDE char result[HASH_32_LEN];
    cx_math_powm(result,
                 point + 1 + HASH_32_LEN, SECP256K1_RES_EXP, HASH_32_LEN,
                 SECP256K1_P, HASH_32_LEN);

    return cx_math_cmp(result, SECP256K1_ONE, 32) == 0;     
}

/**
 * @brief schnoor sign bcrypto 410
 * 
 * @param privateKey 
 * @param hash 
 * @param signature 
 * @return uint32_t 
 */
uint32_t schnorr_sign_bcrypto_410(const uint8_t *privateKey,
                                  const uint8_t *hash,
                                  uint8_t *signature) {
    cx_sha256_t         H;
    unsigned WIDE char  a[HASH_32_LEN];
    unsigned WIDE char  k[HASH_32_LEN];
    unsigned WIDE char  R[PUBLICKEY_UNCOMPRESSED_LEN];
    unsigned WIDE char  A[PUBLICKEY_UNCOMPRESSED_LEN];
    unsigned WIDE char  e[HASH_32_LEN];

    unsigned int d_len      = HASH_32_LEN;
    unsigned int sig_len    = SIG_SCHNORR_LEN;

    unsigned WIDE char G[PUBLICKEY_UNCOMPRESSED_LEN];
    G[0] = 0x04;
    os_memcpy(G + 1, SECP256K1_G, HASH_64_LEN);

    os_memcpy(a, privateKey, d_len);

    if (cx_math_is_zero(a, d_len) ||
        cx_math_cmp(a, SECP256K1_N, d_len) > 0) {
        sig_len = 0;
        goto CLEAR_LOCALS;
    }

    cx_sha256_init(&H);
    cx_hash((cx_hash_t *) &H, 0, a, d_len, NULL, 0);
    cx_hash((cx_hash_t *) &H, CX_LAST | CX_NO_REINIT, hash, d_len, k, d_len);

    if (cx_math_is_zero(k, d_len)) {
        sig_len = 0;
        goto CLEAR_LOCALS;
    }

    os_memcpy(R, G, sizeof(G));
    cx_ecfp_scalar_mult(CX_CURVE_SECP256K1, R, sizeof(R), k, d_len);
    os_memcpy(signature, R + 1, d_len);

    if (cx_math_is_zero(signature, d_len)) {
        MEMSET_BZERO(&signature, SIG_SCHNORR_LEN);
        sig_len = 0;
        goto CLEAR_LOCALS;
    }

    os_memcpy(A, G, sizeof(G));
    cx_ecfp_scalar_mult(CX_CURVE_SECP256K1, A, sizeof(A), a, d_len);

    A[0] = (A[HASH_64_LEN] & 1) == 1 ? 0x03 : 0x02;

    cx_sha256_init(&H);
    cx_hash((cx_hash_t *) &H, 0, signature, d_len, NULL, 0);
    cx_hash((cx_hash_t *) &H, 0, A, PUBLICKEY_COMPRESSED_LEN, NULL, 0);
    cx_hash((cx_hash_t *) &H, CX_LAST | CX_NO_REINIT, hash, d_len, e, d_len);
    cx_math_modm(e, d_len, SECP256K1_N, d_len);

    cx_math_modm(a, d_len, SECP256K1_N, d_len);

    cx_math_modm(k, d_len, SECP256K1_N, d_len);

    if (!hasQuadY(R)) {
        cx_math_sub(k, SECP256K1_N, k, d_len);
    }

    cx_math_multm(e, e, a, SECP256K1_N, d_len);
    cx_math_addm(signature + d_len, k, e, SECP256K1_N, d_len);

    if (cx_math_is_zero(signature + d_len, d_len)) {
        MEMSET_BZERO(signature, SIG_SCHNORR_LEN);
        sig_len = 0;
    }

    CLEAR_LOCALS:
    MEMSET_BZERO((void *)&H, sizeof(H));
    MEMSET_BZERO(&a, sizeof(a));
    MEMSET_BZERO(&k, sizeof(k));
    MEMSET_BZERO(&R, sizeof(R));
    MEMSET_BZERO(&A, sizeof(A));
    MEMSET_BZERO(&e, sizeof(e));

    return sig_len;
}
