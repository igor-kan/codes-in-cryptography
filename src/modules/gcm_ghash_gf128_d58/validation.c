#include "interface.h"

gcm_ghash_gf128_d58_err_t gcm_ghash_gf128_d58_validate_len(size_t n) {
    if (n == 0) {
        return GCM_GHASH_GF128_D58_ERR_INVALID;
    }
    return GCM_GHASH_GF128_D58_OK;
}
