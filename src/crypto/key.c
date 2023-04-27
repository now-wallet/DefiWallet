//
//  key.c
//  NowWallet
//
//  Created by krisna pranav on 27/04/23.
//

#include <stddef.h>
#include <stdint.h>
#include "src/crypto/key.h"
#include "src/consts.h"
#include "utils/util.h"

/**
 * @brief compress public key
 * 
 * @param uncompressed 
 * @param compressed 
 * @return size_t 
 */
size_t compressPublicKey(const uint8_t *uncompressed, uint8_t *compressed) {
    if (uncompressed == NULL || compressed == NULL) {
        return 0;
    }

    const uint8_t EC_PUBLICKEY_EVEN_PREFIX          = 0x02;
    const uint8_t EC_PUBLICKEY_ODD_PREFIX           = 0x03;
    const uint8_t EC_PUBLICKEY_UNCOMPRESSED_PREFIX  = 0x04;

    if (uncompressed[0] != EC_PUBLICKEY_UNCOMPRESSED_PREFIX) {
        return 0;
    }

    compressed[0] = ((uncompressed[HASH_64_LEN] & 1)
            ? EC_PUBLICKEY_ODD_PREFIX
            : EC_PUBLICKEY_EVEN_PREFIX);

    MEMCOPY(&compressed[1], &uncompressed[1], HASH_32_LEN);

    return PUBLICKEY_COMPRESSED_LEN;
}
