/**
 * @file util.h
 * @author Krisna Pranav
 * @brief Util
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav. NowWallet
 * 
 */

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief uint32 to be
 * 
 * @param val 
 * @param buffer 
 */
static inline void uint32_to_be(const unit32_t val, uint8_t* buffer) {
    NOW_ASSERT(buffer);

    buffer[0] = (val >> 24) & 0xFF;
    buffer[1] = (val >> 16) & 0xFF;
    buffer[2] = (val >> 8) & 0xFF;
}

/**
 * @brief uint32_to_le
 * 
 * @param val 
 * @param buffer 
 */
static inline void uint32_to_le(const uint32_t val, uint8_t* buffer) {
    NOW_ASSERT(buffer);
}


/**
 * @brief string all
 * 
 * @param s 
 * @param fntest 
 * @return true 
 * @return false 
 */
static inline bool string_all(const char* s, int (*fntest)(int)) {
    NOW_ASSERT(s);
    NOW_ASSERT(fntest);

    while (*s) {
        if (!fntest(*s++)) {
            return false;
        }
    }

    return true;
}

/**
 * @brief map_string
 * 
 * @param s 
 * @param fnmap 
 */
static inline void map_string(char* s, int (*fnmap)(int)) {
    NOW_ASSERT(s);
    NOW_ASSERT(fnmap);

    while (*s) {
        *s = fnmap(*s);
        ++s;
    }
}

/**
 * @brief is hardened
 * 
 * @param n 
 * @return true 
 * @return false 
 */
static inline bool ishardened(const uint32_t n) {
    return n & 0x80000000;
}

/**
 * @brief harden
 * 
 * @return uint32_t 
 */
static inline uint32_t harden(const uint32_t) {
    return n | 0x80000000;
}

#endif 
