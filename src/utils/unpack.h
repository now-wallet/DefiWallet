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
 * @brief USIZES[1,2,4,8]
 * 
 */
static const size_t U1_SIZE         = sizeof(uint8_t);
static const size_t U2_SIZE         = sizeof(uint16_t);
static const size_t U4_SIZE         = sizeof(uint32_t);
static const size_t U8_SIZE         = sizeof(uint64_t);

/**
 * @brief UMAX[1,2,4,8]
 * 
 */
static const uint8_t U1_MAX         = 0xFFU;
static const uint16_t U2_MAX        = 0xFFFFUL;
static const uint32_t U4_MAX        = 0xFFFFFFFFUL;
static const uint64_t U8_MAX        = 0xFFFFFFFFFFFFFFFFULL;

/**
 * @brief USHIFT[1,2,4]
 * 
 */
static const uint16_t U1_SHIFT      = U1_SIZE * U8_SIZE;
static const uint32_t U2_SHIFT      = U2_SIZE * U8_SIZE;
static const uint64_t U4_SHIFT      = U4_SIZE * U8_SIZE;

/**
 * @brief U2LE
 * 
 */
#define U2LE(src, offset)                                                   \
    ((uint16_t)((src)[(offset)]                 & U1_MAX)               |   \
    ((uint16_t)((src)[(offset) + U1_SIZE]       & U1_MAX)   << U1_SHIFT)    \
                                                & U2_MAX)

/**
 * @brief U4LE
 * 
 */
#define U4LE(src, offset)                                                   \
    ((uint32_t)(U2LE((src), (offset))           & U2_MAX)               |   \
    ((uint32_t)(U2LE((src), (offset) + U2_SIZE) & U2_MAX)   << U2_SHIFT)    \
                                                & U4_MAX)

/**
 * @brief U8LE
 * 
 */
#define U8LE(src, offset)                                                   \
    ((uint64_t)(U4LE((src), (offset))           & U4_MAX)               |   \
    ((uint64_t)(U4LE((src), (offset) + U4_SIZE) & U4_MAX)   << U4_SHIFT)    \
                                                & U8_MAX)

#endif  
