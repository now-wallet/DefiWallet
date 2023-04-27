/**
 * @file unpack.h
 * @author Krisna Pranav
 * @brief UnPack
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_UTILS_UNPACK_H
#define NOW_UTILS_UNPACK_H

#include <stddef.h>
#include <stdint.h>

#if defined(HAVE_BOLOS_SDK)
    #undef U2LE
    #undef U4LE
#endif

/**
 * @brief U1SIZE
 * 
 */
static const size_t U1_SIZE = sizeof(uint8_t);

/**
 * @brief U2SIZE
 * 
 */
static const size_t U2_SIZE = sizeof(uint16_t);

/**
 * @brief U4SIZE
 * 
 */
static const size_t U4_SIZE = sizeof(uint32_t);

/**
 * @brief U8SIZE
 * 
 */
static const size_t U8_SIZE = sizeof(uint64_t);

#define U2LE(src, offset)                                                   \
    ((uint16_t)((src)[(offset)]                 & U1_MAX)               |   \
    ((uint16_t)((src)[(offset) + U1_SIZE]       & U1_MAX)   << U1_SHIFT)    \
                                                & U2_MAX)

#endif