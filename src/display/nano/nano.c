/**
 * @file nano.c
 * @author Krisna Pranav
 * @brief Nano
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023 Krisna Pranav, NowWallet
 *
 */

#include "display/display.h"
#include "platform.h"

#if defined(TARGET_NANOS) || defined(TARGET_NANOX)

#include <stdbool.h>
#include <stdint.h>
#include <cx.h>
#include <ux.h>
#include <os_io_seproxyhal.h>

#include "glyphs.h"
#include "src/approval.h"
#include "display/context/context.h"
#include "utils/util.h"

ux_state_t G_ux;

#if defined(TARGET_NANOX)
    bolos_ux_params_t G_ux_params;
#endif

UX_STEP_NOCB(ux_idle_application_ready, pnn,
             { &C_icon, "Application", "is ready", });

UX_STEP_NOCB(ux_idle_application_version, bn,
             { "Version", APPVERSION, });

UX_STEP_VALID(ux_idle_application_quit, pb,
              ioExit(NULL),
              { &C_icon_dashboard_x, "Quit", });

UX_FLOW(ux_idle_flow, &ux_idle_application_ready,
                      &ux_idle_application_version,
                      &ux_idle_application_quit);

#define UX_STEP_OPERATION { &C_icon_eye,                            \
                            "Operation:", displayCtx.operation }

#define UX_STEP_VAR(x) { .title = displayCtx.title[x],  \
                         .text  = displayCtx.text[x] }

#define UX_STEP_EXT { .title = displayCtx.title_ext,    \
                      .text  = displayCtx.text_ext }

#define UX_STEP_APPROVE { &C_icon_validate_14, "Approve" }
#define UX_STEP_REJECT  { &C_icon_crossmark,   "Reject"  }

UX_STEP_NOCB(ux_step_op, pnn, UX_STEP_OPERATION);

UX_STEP_NOCB(ux_step_1, bnnn_paging, UX_STEP_VAR(0));
UX_STEP_NOCB(ux_step_2, bnnn_paging, UX_STEP_VAR(1));
UX_STEP_NOCB(ux_step_3, bnnn_paging, UX_STEP_VAR(2));
UX_STEP_NOCB(ux_step_4, bnnn_paging, UX_STEP_VAR(3));
UX_STEP_NOCB(ux_step_5, bnnn_paging, UX_STEP_VAR(4));
UX_STEP_NOCB(ux_step_6, bnnn_paging, UX_STEP_VAR(5));
#if defined(SUPPORTS_LARGE_OPERATIONS)
UX_STEP_NOCB(ux_step_7, bnnn_paging, UX_STEP_VAR(6));
UX_STEP_NOCB(ux_step_8, bnnn_paging, UX_STEP_VAR(7));
UX_STEP_NOCB(ux_step_9, bnnn_paging, UX_STEP_VAR(8));
UX_STEP_NOCB(ux_step_10, bnnn_paging, UX_STEP_VAR(9));
UX_STEP_NOCB(ux_step_11, bnnn_paging, UX_STEP_VAR(10));
UX_STEP_NOCB(ux_step_12, bnnn_paging, UX_STEP_VAR(11));
UX_STEP_NOCB(ux_step_13, bnnn_paging, UX_STEP_VAR(12));
UX_STEP_NOCB(ux_step_14, bnnn_paging, UX_STEP_VAR(13));
UX_STEP_NOCB(ux_step_15, bnnn_paging, UX_STEP_VAR(14));
UX_STEP_NOCB(ux_step_16, bnnn_paging, UX_STEP_VAR(15));
UX_STEP_NOCB(ux_step_17, bnnn_paging, UX_STEP_VAR(16));
UX_STEP_NOCB(ux_step_18, bnnn_paging, UX_STEP_VAR(17));
UX_STEP_NOCB(ux_step_19, bnnn_paging, UX_STEP_VAR(18));
UX_STEP_NOCB(ux_step_20, bnnn_paging, UX_STEP_VAR(19));
UX_STEP_NOCB(ux_step_21, bnnn_paging, UX_STEP_VAR(20));
UX_STEP_NOCB(ux_step_22, bnnn_paging, UX_STEP_VAR(21));
UX_STEP_NOCB(ux_step_23, bnnn_paging, UX_STEP_VAR(22));
UX_STEP_NOCB(ux_step_24, bnnn_paging, UX_STEP_VAR(23));
UX_STEP_NOCB(ux_step_25, bnnn_paging, UX_STEP_VAR(24));
UX_STEP_NOCB(ux_step_26, bnnn_paging, UX_STEP_VAR(25));
UX_STEP_NOCB(ux_step_27, bnnn_paging, UX_STEP_VAR(26));
UX_STEP_NOCB(ux_step_28, bnnn_paging, UX_STEP_VAR(27));
UX_STEP_NOCB(ux_step_29, bnnn_paging, UX_STEP_VAR(28));
UX_STEP_NOCB(ux_step_30, bnnn_paging, UX_STEP_VAR(29));
UX_STEP_NOCB(ux_step_31, bnnn_paging, UX_STEP_VAR(30));
UX_STEP_NOCB(ux_step_32, bnnn_paging, UX_STEP_VAR(31));
UX_STEP_NOCB(ux_step_33, bnnn_paging, UX_STEP_VAR(32));
UX_STEP_NOCB(ux_step_34, bnnn_paging, UX_STEP_VAR(33));
UX_STEP_NOCB(ux_step_35, bnnn_paging, UX_STEP_VAR(34));
UX_STEP_NOCB(ux_step_36, bnnn_paging, UX_STEP_VAR(35));
UX_STEP_NOCB(ux_step_37, bnnn_paging, UX_STEP_VAR(36));
UX_STEP_NOCB(ux_step_38, bnnn_paging, UX_STEP_VAR(37));
UX_STEP_NOCB(ux_step_39, bnnn_paging, UX_STEP_VAR(38));
UX_STEP_NOCB(ux_step_40, bnnn_paging, UX_STEP_VAR(39));
#endif  

UX_STEP_NOCB(ux_step_ext, bnnn_paging, UX_STEP_EXT);

UX_STEP_VALID(ux_step_approve, pb, ioApprove(NULL), UX_STEP_APPROVE);
UX_STEP_VALID(ux_step_reject, pb, ioCancel(NULL), UX_STEP_REJECT);

#define UX_FLOW_CONTAINTER_MAX (1 + (DISPLAY_CTX_STEP_COUNT + 1) + 3)

const ux_flow_step_t* const ux_flow_container_[1 + DISPLAY_CTX_STEP_COUNT] = {
    &ux_step_op,
    &ux_step_1, &ux_step_2, &ux_step_3, &ux_step_4, &ux_step_5,
#if defined(SUPPORTS_LARGE_OPERATIONS)
    &ux_step_6, &ux_step_7, &ux_step_8, &ux_step_9, &ux_step_10,
    &ux_step_11, &ux_step_12, &ux_step_13, &ux_step_14, &ux_step_15,
    &ux_step_16, &ux_step_17, &ux_step_18, &ux_step_19, &ux_step_20,
    &ux_step_21, &ux_step_22, &ux_step_23, &ux_step_24, &ux_step_25,
    &ux_step_26, &ux_step_27, &ux_step_28, &ux_step_29, &ux_step_30,
    &ux_step_31, &ux_step_32, &ux_step_33, &ux_step_34, &ux_step_35,
    &ux_step_36, &ux_step_37, &ux_step_38, &ux_step_39, &ux_step_40,
#endif  
};

/**
 * @brief ux flow container
 * 
 */
ux_flow_step_t* ux_flow_container[UX_FLOW_CONTAINTER_MAX];

/**
 * @brief ux float container init
 * 
 * @param steps 
 * @param extendedStep 
 */
void ux_flow_container_init(size_t steps, size_t extendedStep) {
    MEMSET_BZERO(ux_flow_container, sizeof(ux_flow_container));

    os_memmove(ux_flow_container, ux_flow_container_, sizeof(ux_flow_container_));

    if (extendedStep > 0U) {
        ux_flow_container[extendedStep] = (ux_flow_step_t *)&ux_step_ext;
    }

    ux_flow_container[steps + 1] = (ux_flow_step_t *)&ux_step_approve;
    ux_flow_container[steps + 2] = (ux_flow_step_t *)&ux_step_reject;
    ux_flow_container[steps + 3] = FLOW_END_STEP;
}

/**
 * @brief Set the Ux Display object
 * 
 * @param steps 
 * @param extendedStep 
 */
void setUxDisplay(size_t steps, size_t extendedStep) {
    ux_flow_container_init(steps, extendedStep);
    ux_flow_init(0U, (const ux_flow_step_t *const *)ux_flow_container, NULL);
}

/**
 * @brief ui_idle
 * 
 */
void ui_idle(void) {
    if (G_ux.stack_count == 0) {
        ux_stack_push();
    }
    ux_flow_init(0, ux_idle_flow, NULL);
}

#endif  
