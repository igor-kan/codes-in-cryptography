#include "interface.h"

siphash_2_4_prf_d60_err_t siphash_2_4_prf_d60_validate_len(size_t n) {
    if (n == 0) {
        return SIPHASH_2_4_PRF_D60_ERR_INVALID;
    }
    return SIPHASH_2_4_PRF_D60_OK;
}
