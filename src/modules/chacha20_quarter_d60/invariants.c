#include "interface.h"

chacha20_quarter_d60_err_t chacha20_quarter_d60_verify_guard(bool cond) {
    if (!cond) {
        return CHACHA20_QUARTER_D60_ERR_INVARIANT;
    }
    return CHACHA20_QUARTER_D60_OK;
}
