#include "interface.h"

rabin_miller_u64_d59_err_t rabin_miller_u64_d59_validate_len(size_t n) {
    if (n == 0) {
        return RABIN_MILLER_U64_D59_ERR_INVALID;
    }
    return RABIN_MILLER_U64_D59_OK;
}
