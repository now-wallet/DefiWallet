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

static const char *const UX_MESSAGE_LABELS[] = {"Message", "Length"};
static const size_t UX_MESSAGE_STEPS = 2;

extern void setUxDisplay(size_t steps, size_t extendedStep);



#endif 