/**
 * @file signing.c
 * @author Krisna Pranav
 * @brief Signing
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#include <stdint.h>
#include <os.h>
#include <cx.h>

#include "signing.h"
#include "src/consts.h"
#include "src/crypto/schnorr_bcrypto_410.h"

/**
 * @brief sign ecdsa
 * 
 * @param privateKey 
 * @param hash 
 * @param signature 
 * @param signatureSize 
 * @return uint32_t 
 */
uint32_t signEcdsa(const cx_ecfp_private_key_t *privateKey,
                   const uint8_t *hash,
                   uint8_t *signature,
                   size_t signatureSize) {
    if (privateKey == NULL || hash == NULL || signature == NULL ||
        signatureSize < SIG_ECDSA_MIN_LEN ||
        signatureSize > SIG_ECDSA_MAX_LEN) {
        return 0;
    }

    return cx_ecdsa_sign(privateKey,
                         CX_RND_RFC6979 | CX_LAST, CX_SHA256,
                         hash, HASH_32_LEN,
                         signature, signatureSize,
                         NULL);
} 

/**
 * @brief signschnorr
 * 
 * @param privateKey 
 * @param hash 
 * @param signature 
 * @return uint32_t 
 */
uint32_t signSchnorr(const cx_ecfp_private_key_t *privateKey,
                     const uint8_t *hash,
                     uint8_t *signature) {
    if (privateKey == NULL || hash == NULL || signature == NULL) {
        return 0;
    }

    return schnorr_sign_bcrypto_410(privateKey->d, hash, signature);
}