#include "interface.h"

chacha_quarter_round_d56_err_t chacha_quarter_round_d56_verify_guard(bool cond) {
    if (!cond) {
        return CHACHA_QUARTER_ROUND_D56_ERR_INVARIANT;
    }
    return CHACHA_QUARTER_ROUND_D56_OK;
}
