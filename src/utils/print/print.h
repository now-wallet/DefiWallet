/**
 * @file print.h
 * @author Krisna Pranav
 * @brief Print Functionality
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */

#ifndef NOW_PRINT_H
#define NOW_PRINT_H

#if defined(HAVE_BOLOS_SDK)
    #include <os.h>
    #include <os_io_seproxyhal.h>

    #undef SPRINTF  
    #define SPRINTF_(strbuf, ...) snprintf(strbuf, sizeof(strbuf), __VA_ARGS__)

    #define SNPRINTF_ snprintf
#else  
    #include <string.h>

    #define SPRINTF_ sprintf
    #define SNPRINTF_ snprintf
#endif  

#define SPRINTF SPRINTF_

#define SNPRINTF SNPRINTF_

#endif  
