/**
 * @file util.h
 * @author Krisna Pranav
 * @brief Util
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_UTIL_H
#define NOW_UTIL_H

#if defined(HAVE_BOLOS_SDK)
    #include <os.h>
    #include <os_io_seproxyhal.h>

    #define MEMCOPY_ os_memmove
    #define MEMSET_ os_memset
    #define MEMSET_BZERO
#endif 

#endif