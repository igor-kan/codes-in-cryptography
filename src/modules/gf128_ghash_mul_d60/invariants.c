#include "interface.h"

gf128_ghash_mul_d60_err_t gf128_ghash_mul_d60_verify_guard(bool cond) {
    if (!cond) {
        return GF128_GHASH_MUL_D60_ERR_INVARIANT;
    }
    return GF128_GHASH_MUL_D60_OK;
}
