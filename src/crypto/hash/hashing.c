/**
 * @file hashing.c
 * @author Krisna Pranav
 * @brief Hashing
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#include <stddef.h>
#include <stdint.h>
#include <os.h>
#include <cx.h>
#include "crypto/hash/hashing.h"

/**
 * @brief hash256 
 * 
 * @param in 
 * @param inSize 
 * @param out 
 */
void hash256(uint8_t *in, size_t inSize, uint8_t *out) {
    cx_sha256_t ctx;
    cx_sha256_init(&ctx);
    cx_hash(&ctx.header, CX_LAST, in, inSize, out, CX_SHA256_SIZE);
}