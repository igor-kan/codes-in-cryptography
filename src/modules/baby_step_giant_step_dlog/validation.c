#include "interface.h"

baby_step_giant_step_dlog_err_t baby_step_giant_step_dlog_validate_len(size_t n) {
    if (n == 0) {
        return BABY_STEP_GIANT_STEP_DLOG_ERR_INVALID;
    }
    return BABY_STEP_GIANT_STEP_DLOG_OK;
}
