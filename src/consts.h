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

#if defined(SUPPORTS_LARGE_OPERATIONS)
    static const size_t MAX_RAW_OPERATION = 2496;
#else
    static const size_t MAX_RAW_OPERATION = 704;
#endif 

static const size_t MAX_TEXT_LEN = 255;

static const size_t HASH_20_LEN = 20;
static const size_t HASH_32_LEN = 32;
static const size_t HASH_64_LEN = 64;

static const uint64_t UINT64_BASE_10 = 10U;

static const size_t TOKEN_DECIMALS = 8U;
static const char *const TOKEN_NAME = "NOW";
static const size_t TOKEN_NAME_LEN = 3U;
static const uint8_t TOKEN_NETWORK_BYTE = 0x1e;

static const uint8_t TRANSACTION_HEADER = 0xFF;

#endif