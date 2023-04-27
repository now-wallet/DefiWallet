/**
 * @file signing.h
 * @author Krisna Pranav
 * @brief Signing
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_CRYPTO_SIGNING_H
#define NOW_CRYPTO_SIGNING_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <os.h>
#include <cx.h>

#include "src/consts.h"

/**
 * @brief signing context
 * 
 */
typedef struct signing_context_t {
    cx_curve_t  curve;
    uint8_t     pathLength;
    uint32_t    bip32Path[ADDRESS_MAX_BIP32_PATH];
    uint8_t     data[MAX_RAW_OPERATION];
    uint32_t    dataLength;
    bool        isSchnorr;
} SigningContext;

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
                   size_t signatureSize);

/**
 * @brief sign schnorr
 * 
 * @param privateKey 
 * @param hash 
 * @param signature 
 * @return uint32_t 
 */
uint32_t signSchnorr(const cx_ecfp_private_key_t *privateKey,
                     const uint8_t *hash,
                     uint8_t *signature);

#endif 
