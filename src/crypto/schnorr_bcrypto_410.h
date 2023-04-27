/**
 * @file schnorr_bcrypto_410.h
 * @author Krisna Pranav
 * @brief Schnoor Bcrypto 410
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_CRYPTO_SCHNORR_BCRYPTO_410_H
#define NOW_CRYPTO_SCHNORR_BCRYPTO_410_H

#include <stdint.h>

/**
 * @brief schnorr sign bcrypto 410
 * 
 * @param privateKey 
 * @param hash 
 * @param signature 
 * @return uint32_t 
 */
uint32_t schnorr_sign_bcrypto_410(const uint8_t *privateKey,
                                  const uint8_t *hash,
                                  uint8_t *signature);

#endif  