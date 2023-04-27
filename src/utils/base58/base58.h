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
 * @brief base58 encoding
 * 
 * @param in 
 * @param length 
 * @param out 
 * @param outlen 
 * @return int 
 */
int base58Encode(const uint8_t *in, size_t length, char *out, size_t *outlen);

/**
 * @brief check encode
 * 
 * @param in 
 * @param length 
 * @param out 
 * @param outLen 
 * @return int 
 */
int base58CheckEncode(const uint8_t *in, size_t length, char *out, size_t outLen);

#endif  
