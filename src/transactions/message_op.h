/**
 * @file message_op.h
 * @author Krisna Pranav
 * @brief 
 * @version 0.1
 * @date 2023-05-02
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_TRANSACTIONS_MESSAGE_H
#define NOW_TRANSACTIONS_MESSAGE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// now_libraries
#include "src/consts.h"
#include "utils/print/print.h"
#include "utils/str.h"
#include "utils/util.h"
#include "display/context/context.h"
#include "display/display.h"

/**
 * @brief UX_MESSAGE[LABELS, STEPS]
 * 
 */
static const char *const UX_MESSAGE_LABELS[]    = { "Message", "Length" };
static const size_t UX_MESSAGE_STEPS            = 2;

/**
 * @brief Set the Ux Display object
 * 
 * @param steps 
 * @param extendedStep 
 */
extern void setUxDisplay(size_t steps, size_t extendedStep);

/**
 * @brief handleMsg
 * 
 * @param buffer 
 * @param length 
 * @return true 
 * @return false 
 */
bool handleMessage(const uint8_t *buffer, size_t length) {
    MEMSET_TYPE_BZERO(&displayCtx, DisplayContext);

    if (length == 0 || length > MAX_TEXT_LEN) {
        return false;
    }

    SPRINTF(displayCtx.operation, "%s", UX_MESSAGE_LABELS[0]);
    SPRINTF(displayCtx.title[0], "%s:", UX_MESSAGE_LABELS[1]);
    SPRINTF(displayCtx.title_ext, "%s:", UX_MESSAGE_LABELS[0]);

    UintToString(length, displayCtx.text[0], sizeof(displayCtx.text[0]));

    if (!IsPrintableAscii((const char*)buffer, length, false)) {
        return false;
    }

    SNPRINTF(displayCtx.text_ext, length + 1, "%.*s", (int)length, buffer);

    setUxDisplay(UX_MESSAGE_STEPS, UX_MESSAGE_STEPS);

    return true;
}

#endif 