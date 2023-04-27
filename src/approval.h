/**
 * @file approval.h
 * @author Krisna Pranav
 * @brief Approval
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 * 
 */


#ifndef NOW_APPROVAL_H
#define NOW_APPROVAL_H

#include <ux.h>
#include <os_io_seproxyhal.h>

/**
 * @brief ioApprove
 * 
 * @param e 
 * @return unsigned int 
 */
unsigned int ioApprove(const bagl_element_t *e);

/**
 * @brief ioCancel
 * 
 * @param e 
 * @return unsigned int 
 */
unsigned int ioCancel(const bagl_element_t *e);

/**
 * @brief ioExit
 * 
 * @param e 
 * @return unsigned int 
 */
unsigned int ioExit(const bagl_element_t *e);

#endif 