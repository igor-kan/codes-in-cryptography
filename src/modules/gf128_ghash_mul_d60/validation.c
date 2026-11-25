#include "interface.h"

gf128_ghash_mul_d60_err_t gf128_ghash_mul_d60_validate_len(size_t n) {
    if (n == 0) {
        return GF128_GHASH_MUL_D60_ERR_INVALID;
    }
    return GF128_GHASH_MUL_D60_OK;
}
