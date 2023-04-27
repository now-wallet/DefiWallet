/**
 * @file consts.h
 * @author Krisna Pranav
 * @brief Consts
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_CONST_H
#define NOW_CONST_H

#include <stddef.h>
#include <stdint.h>
#include "platform.h"

/**
 * @brief Supports Large Operation
 * 
 */
#if defined(SUPPORTS_LARGE_OPERATIONS)
    static const size_t MAX_RAW_OPERATION   = 2496;     
#else
    static const size_t MAX_RAW_OPERATION   = 704;      
#endif

/**
 * @brief Text Length(255)
 * 
 */
static const size_t MAX_TEXT_LEN = 255;

/**
 * @brief Hash[20, 32, 64]
 * 
 */
static const size_t HASH_20_LEN     = 20;
static const size_t HASH_32_LEN     = 32;
static const size_t HASH_64_LEN     = 64;

/**
 * @brief Address[Len, Hash_Len, MaxPath, Compressed Length, UnCompress Length]
 * 
 */
static const size_t ADDRESS_LEN                     = 34;
static const size_t ADDRESS_HASH_LEN                = 21;
static const size_t ADDRESS_MAX_BIP32_PATH          = 10;
static const size_t PUBLICKEY_COMPRESSED_LEN        = 33;
static const size_t PUBLICKEY_UNCOMPRESSED_LEN      = 65;

/**
 * @brief UX Label[Amount, Expiration, Fee, Recipient]
 * 
 */
static const char *const UX_LABEL_AMOUNT        = "Amount";
static const char *const UX_LABEL_EXPIRATION    = "Expiration";
static const char *const UX_LABEL_FEE           = "Fee";
static const char *const UX_LABEL_RECIPIENT     = "Recipient";

/**
 * @brief uint64 BASE
 * 
 */
static const uint64_t UINT64_BASE_10 = 10U;

/**
 * @brief sig functionalities
 * 
 */
static const size_t SIG_ECDSA_MIN_LEN   = 64;
static const size_t SIG_ECDSA_MAX_LEN   = 72;
static const size_t SIG_SCHNORR_LEN     = HASH_64_LEN;

/**
 * @brief token functionalities[decimals, token name, token name length, token network byte]
 * 
 */
static const size_t TOKEN_DECIMALS          = 8U;
static const char *const TOKEN_NAME         = "NOW";
static const size_t TOKEN_NAME_LEN          = 3U;       
static const uint8_t TOKEN_NETWORK_BYTE     = 0x1e;     

/**
 * @brief transaction header
 * 
 */
static const uint8_t TRANSACTION_HEADER             = 0xFF;

/**
 * @brief Transaction versions 
 * 
 */
static const uint8_t TRANSACTION_VERSION_TYPE_1     = 1;
static const uint8_t TRANSACTION_VERSION_TYPE_2     = 2;

/**
 * @brief vendor field
 * 
 */
static const uint8_t VENDORFIELD_V1_MAX_LEN = 64;
static const uint8_t VENDORFIELD_V2_MAX_LEN = 255;

#endif  
