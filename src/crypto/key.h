/**
 * @file key.h
 * @author Krisna Pranav
 * @brief Key
 * @version 0.1
 * @date 2023-04-27
 *  
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 *  
 */

#ifndef NOW_CRYPTO_KEY_H
#define NOW_CRYPTO_KEY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "src/consts.h"

typedef struct public_key_context_t {
    uint8_t     data[PUBLICKEY_UNCOMPRESSED_LEN];
    uint8_t     chainCode[HASH_32_LEN];
    bool        needsChainCode;
} PublicKeyContext;

/**
 * @brief compress public key
 * 
 * @param uncompressed 
 * @param compressed 
 * @return size_t 
 */
size_t compressPublicKey(const uint8_t *uncompressed, uint8_t *compressed);

#endif  
