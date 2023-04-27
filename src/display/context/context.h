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

#ifndef NOW_DISPLAY_CONTEXT_H
#define NOW_DISPLAY_CONTEXT_H

#include <stddef.h>
#include "src/platform.h"

static const size_t DISPLAY_CTX_TEXT_SIZE_EXT = 256;
static const size_t DISPLAY_CTX_OP_SIZE     = 21;

typedef struct display_context_t {
    char operation [DISPLAY_CTX_OP_SIZE]
} DisplayContext;

extern DisplayContext displayCtx;

#endif
