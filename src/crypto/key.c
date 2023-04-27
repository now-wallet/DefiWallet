//
//  key.c
//  NowWallet
//
//  Created by krisna pranav on 27/04/23.
//

#include <stddef.h>
#include <stdint.h>
#include "crypto/key.h"
#include "src/consts.h"
#include "utils/util.h"

size_t compressPublicKey(const uint8_t *uncompressed, uint8_t *compressed) {
    if (uncompressed == NULL || compressed == NULL) {
        return 0;
    }
    
    const uint8_t EC_PUBLICKEY_EVEN_PREFIX = 0x02;
    const uint8_t EC_PUBLICKEY_ODD_PREFIX = 0x03;
    const uint8_t EC_PUBLICKEY_UNCOMPRESSED_PREFIX = 0x04;

    return EC_PUBLICKEY_UNCOMPRESSED_PREFIX;
}
