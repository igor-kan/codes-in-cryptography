#include "interface.h"

siphash_2_4_prf_d60_err_t siphash_2_4_prf_d60_verify_guard(bool cond) {
    if (!cond) {
        return SIPHASH_2_4_PRF_D60_ERR_INVARIANT;
    }
    return SIPHASH_2_4_PRF_D60_OK;
}
