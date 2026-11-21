#include "interface.h"

shamir_lagrange_gf257_d56_err_t shamir_lagrange_gf257_d56_validate_len(size_t n) {
    if (n == 0) {
        return SHAMIR_LAGRANGE_GF257_D56_ERR_INVALID;
    }
    return SHAMIR_LAGRANGE_GF257_D56_OK;
}
