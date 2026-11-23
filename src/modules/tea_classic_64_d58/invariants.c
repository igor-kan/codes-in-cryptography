#include "interface.h"

tea_classic_64_d58_err_t tea_classic_64_d58_verify_guard(bool cond) {
    if (!cond) {
        return TEA_CLASSIC_64_D58_ERR_INVARIANT;
    }
    return TEA_CLASSIC_64_D58_OK;
}
