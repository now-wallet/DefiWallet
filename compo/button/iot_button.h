/**
 * @file iot_button.h
 * @author Krisna Pranav
 * @brief IOT Button Functionalities
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav. NowWallet
 * 
 */

#pragma once

#ifdef __cplusplus 
extern "C" {
#endif

typedef void (* button_cb)(void*);
typedef void* button_handle_t;

typedef enum {
    BUTTON_ACTIVE_HIGH = 1,
    BUTTON_ACTIVE_LOW = 0,
} button_active_t;

}