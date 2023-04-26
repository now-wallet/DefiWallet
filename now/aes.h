#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <wally_crypto.h>

#define AES_PADDED_LEN(len) (((len / AES_BLOCK_LEN ) + 1) * AES_BLOCK_LEN)
#define AES_ENCRYPTED_LEN(len) (AES_BLOCK_LEN + AES_PADDED_LEN(len))

/**
 * @brief aes encrypted bytes
 * 
 */
bool aes_encrypt_bytes(const uint8_t* aeskey, size_t asekey_len, const uint8_t* bytes, size_t bytes_len, uint8_t* output, size_t output_len)
