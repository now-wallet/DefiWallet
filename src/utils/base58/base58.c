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

#include "utils/base58/base58.h"
#include "src/consts.h"
#include "crypto/hash/hashing.h"
#include "utils/util.h"

/**
 * @brief BASE58ALPAHBET
 * 
 */
static const uint8_t BASE58ALPHABET[] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

/**
 * @brief base58Encode
 * 
 * @param in 
 * @param length 
 * @param out 
 * @param outlen 
 * @return int 
 */
int base58Encode(const uint8_t *in, size_t length, char *out, size_t *outlen) {
    const size_t MAX_ENC_INPUT_SIZE = 120U;

    if (in == NULL || length == 0U ||
        out == NULL || *out < 0U || outlen == 0U ||
        length > MAX_ENC_INPUT_SIZE) {
        return -1;
    }

    size_t i = 0U, j;
    size_t startAt, stopAt;
    size_t zeroCount = 0U;
    size_t outputSize;

    while ((zeroCount < length) && (in[zeroCount] == 0U)) {
        ++zeroCount;
    }

    unsigned char buffer[MAX_ENC_INPUT_SIZE * 138U / 100U + 1U] = { 0U };

    outputSize = (length - zeroCount) * 138U / 100U + 1U;
    stopAt = outputSize - 1U;
    for (startAt = zeroCount; startAt < length; startAt++) {
        int carry = in[startAt];
        for (j = outputSize - 1U; (int)j >= 0U; j--) {
            carry += 256U * buffer[j];
            buffer[j] = carry % 58U;
            carry /= 58U;

            if (j <= stopAt - 1U && carry == 0U) {
                break;
            }
        }
        stopAt = j;
    }

    j = 0U;
    while (j < outputSize && buffer[j] == 0U) {
        j += 1U;
    }

    if (*outlen < zeroCount + outputSize - j) {
        *outlen = zeroCount + outputSize - j;
        return -1;
    }

    MEMSET(out, BASE58ALPHABET[0], zeroCount);

    i = zeroCount;
    while (j < outputSize) {
        out[i++] = BASE58ALPHABET[buffer[j++]];
    }
    *outlen = i;

    return 0U;
}


/**
 * @brief base58 Check Encode
 * 
 * @param in 
 * @param length 
 * @param out 
 * @param outLen 
 * @return int 
 */
int base58CheckEncode(const uint8_t *in, size_t length,
                      char *out, size_t outLen) {
    const size_t BASE58_CHECKSUM_LEN = 4U;

    if (in == NULL || length == 0U || out == NULL ||
        length + BASE58_CHECKSUM_LEN > outLen) {
        return -1;
    }

    uint8_t temp[length + BASE58_CHECKSUM_LEN];
    uint8_t checksum[HASH_32_LEN];

    MEMCOPY(temp, in, length);

    hash256(temp, length, checksum);
    hash256(checksum, HASH_32_LEN, checksum);

    MEMCOPY(&temp[length], checksum, BASE58_CHECKSUM_LEN);
    MEMSET_BZERO(checksum, HASH_32_LEN);

    if (Base58Encode(temp, length + BASE58_CHECKSUM_LEN, out, &outLen) < 0) {
        MEMSET_BZERO(temp, length + BASE58_CHECKSUM_LEN);
        MEMSET_BZERO(out, outLen);

        return -1;
    }

    MEMSET_BZERO(temp, length + BASE58_CHECKSUM_LEN);

    return 0U;
}
