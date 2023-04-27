//
//  key.h
//  NowWallet
//
//  Created by krisna pranav on 27/04/23.
//

#ifndef NOW_CRYPTO_KEY_H
#define NOW_CRYPTO_KEY_H


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "src/consts.h"

/**
 * @brief compress public key
 * 
 * @param uncompressed 
 * @param compressed 
 * @return size_t 
 */
size_t compressPublicKey(const uint8_t *uncompressed, uint8_t *compressed);

#endif
