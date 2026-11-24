#include "interface.h"

rabin_miller_u64_d59_err_t rabin_miller_u64_d59_verify_guard(bool cond) {
    if (!cond) {
        return RABIN_MILLER_U64_D59_ERR_INVARIANT;
    }
    return RABIN_MILLER_U64_D59_OK;
}
