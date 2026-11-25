#include "interface.h"

fe25519_arith_d60_err_t fe25519_arith_d60_validate_len(size_t n) {
    if (n == 0) {
        return FE25519_ARITH_D60_ERR_INVALID;
    }
    return FE25519_ARITH_D60_OK;
}
