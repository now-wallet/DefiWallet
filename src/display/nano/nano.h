/**
 * @file nano.h
 * @author Krisna Pranav
 * @brief Nano
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 *
 */

#ifndef NOW_NANO_H
#define NOW_NANO_H

#include <stdint.h>

/**
 * @brief Set the Ux Display object
 * 
 * @param steps 
 * @param extendedStep 
 */
void setUxDisplay(size_t steps, size_t extendedStep);

/**
 * @brief ui idle
 * 
 */
void ui_idle(void);

#endif
