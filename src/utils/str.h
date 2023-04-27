/**
 * @file str.h
 * @author Krisna Pranav
 * @brief Str
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_UTILS_STR_H
#define NOW_UTILS_STR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief check is that an printable ascii
 * 
 * @param str 
 * @param length 
 * @param isNullTerminated 
 * @return true 
 * @return false 
 */
bool IsPrintableAscii(const char *str, size_t length, bool isNullTerminated);

/**
 * @brief Uint -> String
 * 
 * @param value 
 * @param dst 
 * @param maxLen 
 * @return size_t 
 */
size_t UintToString(uint64_t value, char *dst, size_t maxLen);


#endif 