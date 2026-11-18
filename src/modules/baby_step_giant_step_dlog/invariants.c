#include "interface.h"

baby_step_giant_step_dlog_err_t baby_step_giant_step_dlog_verify_guard(bool cond) {
    if (!cond) {
        return BABY_STEP_GIANT_STEP_DLOG_ERR_INVARIANT;
    }
    return BABY_STEP_GIANT_STEP_DLOG_OK;
}
