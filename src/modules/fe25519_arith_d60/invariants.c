#include "interface.h"

fe25519_arith_d60_err_t fe25519_arith_d60_verify_guard(bool cond) {
    if (!cond) {
        return FE25519_ARITH_D60_ERR_INVARIANT;
    }
    return FE25519_ARITH_D60_OK;
}
