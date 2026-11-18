#include "interface.h"

fletcher64_adler32_dual_err_t fletcher64_adler32_dual_verify_guard(bool cond) {
    if (!cond) {
        return FLETCHER64_ADLER32_DUAL_ERR_INVARIANT;
    }
    return FLETCHER64_ADLER32_DUAL_OK;
}
