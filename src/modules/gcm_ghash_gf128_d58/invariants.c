#include "interface.h"

gcm_ghash_gf128_d58_err_t gcm_ghash_gf128_d58_verify_guard(bool cond) {
    if (!cond) {
        return GCM_GHASH_GF128_D58_ERR_INVARIANT;
    }
    return GCM_GHASH_GF128_D58_OK;
}
