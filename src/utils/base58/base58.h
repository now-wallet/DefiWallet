/**
 * @file base58.h
 * @author Krisna Pranav
 * @brief Base58 Header 
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_BASE58_H
#define NOW_BASE58_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief base58 Encode
 * 
 * @param in 
 * @param length 
 * @param out 
 * @param outlen 
 * @return int 
 */
int base58Encode(const uint8_t *in, size_t length, char *out, size_t *outlen);

/**
 * @brief base58 check
 * 
 * @param in 
 * @param length 
 * @return int 
 */
int base58Check(const uint8_t *in, size_t length);

#endif