/**
 * @file aes.h
 * @author Krisna Pranav
 * @brief AES Encryption
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav. NowWallet
 * 
 */

#ifndef NOW_AES_H
#define NOW_AES_H

#include <stdbool.h>
#include <stddef.h>
#include <wally_crypto.h>

/**
 * @brief AES PADDED LEN + AES ENCRYPTED LEN
 * 
 */
#define AES_PADDED_LEN(len) (((len / AES_BLOCK_LEN) + 1) * AES_BLOCK_LEN)
#define AES_ENCRYPTED_LEN(len) (AES_BLOCK_LEN + AES_PADDED_LEN(len))

/**
 * @brief aes encrypt bytes
 * 
 * @param aeskey 
 * @param aeskey_len 
 * @param bytes 
 * @param bytes_len 
 * @param output 
 * @param output_len 
 * @return true 
 * @return false 
 */
bool aes_encrypt_bytes(const uint8_t* aeskey, size_t aeskey_len, const uint8_t* bytes, size_t bytes_len, uint8_t* output, size_t output_len);

/**
 * @brief aes decrypt bytes
 * 
 * @param aeskey 
 * @param aeskey_len 
 * @param bytes 
 * @param bytes_len 
 * @param output 
 * @param output_len 
 * @param written 
 * @return true 
 * @return false 
 */
bool aes_decrypt_bytes(const uint8_t* aeskey, size_t aeskey_len, const uint8_t* bytes, size_t bytes_len, uint8_t* output, size_t output_len, size_t* written);

#endif 