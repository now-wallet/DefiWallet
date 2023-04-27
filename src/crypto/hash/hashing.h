/**
 * @file hashing.h
 * @author Krisna Pranav
 * @brief Hashing
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_CRYPTO_HASHING_H
#define NOW_CRYPTO_HASHING_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief hash256
 * 
 * @param in 
 * @param inSize 
 * @param out 
 */
void hash256(uint8_t *in, size_t inSize, uint8_t *out);

#endif 