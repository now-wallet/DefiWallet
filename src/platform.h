/**
 * @file platform.h
 * @author Krisna Pranav
 * @brief 
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_PLATFORM_H
#define NOW_PLATFORM_H

#if defined(HAVE_BOLOS_SDK)
    #include <os.h>

    #if defined(TARGET_NANOX)
        #define SUPPORTS_LARGE_OPERATIONS
        #define SUPPORTS_MULTISIGNATURE
    #endif
#endif

#endif