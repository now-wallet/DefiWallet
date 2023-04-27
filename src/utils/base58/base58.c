/**
 * @file base58.c
 * @author Krisna Pranav
 * @brief base58 
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "src/consts.h"
#include "utils/util.h"
#include "crypto/hash/hashing.h"

static const uint8_t BASE58ALPHABET[] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

int base58Encode(const uint8_t *in, size_t length, char *out, size_t *outlen) {
    const size_t MAX_ENC_INPUT_SIZE = 120U;
    
    if (in == NULL || length == 0U ||
        out == NULL || *out < 0U || outlen == 0U ||
        length > MAX_ENC_INPUT_SIZE) {
            return -1
    }

    size_t i = 0U, j;

    size_t startAt, stopAt;

    size_t zeroCount = 0U;

    size_t outputSize;

    while ((zeroCount < length) && (in[zeroCount] == 0u)) {
        ++zeroCount
    }

    unsigned char buffer[MAX_ENC_INPUT_SIZE * 138U / 100 + 1U] = { 0U };

    outputSize = (length - zeroCount) * 138U / 100U;
}