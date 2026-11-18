#include "interface.h"

fletcher64_adler32_dual_err_t fletcher64_adler32_dual_validate_len(size_t n) {
    if (n == 0) {
        return FLETCHER64_ADLER32_DUAL_ERR_INVALID;
    }
    return FLETCHER64_ADLER32_DUAL_OK;
}
