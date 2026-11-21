#include "interface.h"

shamir_lagrange_gf257_d56_err_t shamir_lagrange_gf257_d56_verify_guard(bool cond) {
    if (!cond) {
        return SHAMIR_LAGRANGE_GF257_D56_ERR_INVARIANT;
    }
    return SHAMIR_LAGRANGE_GF257_D56_OK;
}
