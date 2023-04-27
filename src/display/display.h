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

#ifndef NOW_DISPLAY_H
#define NOW_DISPLAY_H

#include "src/platform.h"

#if defined(TARGET_NANOS) || defined(TARGET_NANOX)
    #include "display/nano/nano.h"
#endif

#endif
