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

/**
 * @brief DISPLAY_CTX_TEXT_SIZE_EXT
 * 
 */
static const size_t DISPLAY_CTX_TEXT_SIZE_EXT   = 256;

/**
 * @brief DISPLAY_CTX[OP_SIZE, STEP_COUNT, TITLE_SIZE]
 * 
 */
#if defined(SUPPORTS_LARGE_OPERATIONS)
    static const size_t DISPLAY_CTX_OP_SIZE     = 21;
    static const size_t DISPLAY_CTX_STEP_COUNT  = 40;
    static const size_t DISPLAY_CTX_TITLE_SIZE  = DISPLAY_CTX_OP_SIZE - 1;
    static const size_t DISPLAY_CTX_TEXT_SIZE   = 130;
#else
    static const size_t DISPLAY_CTX_OP_SIZE     = 18;
    static const size_t DISPLAY_CTX_STEP_COUNT  = 5;
    static const size_t DISPLAY_CTX_TITLE_SIZE  = DISPLAY_CTX_OP_SIZE - 3;
    static const size_t DISPLAY_CTX_TEXT_SIZE   = 68;
#endif

/**
 * @brief display_context_t
 * 
 */
typedef struct display_context_t {
    char    operation   [DISPLAY_CTX_OP_SIZE];
    char    title       [DISPLAY_CTX_STEP_COUNT] [DISPLAY_CTX_TITLE_SIZE];
    char    text        [DISPLAY_CTX_STEP_COUNT] [DISPLAY_CTX_TEXT_SIZE];

    char    title_ext   [DISPLAY_CTX_TITLE_SIZE];
    char    text_ext    [DISPLAY_CTX_TEXT_SIZE_EXT];
} DisplayContext;

/**
 * @brief displayCtx
 * 
 */
extern DisplayContext displayCtx;

#endif  