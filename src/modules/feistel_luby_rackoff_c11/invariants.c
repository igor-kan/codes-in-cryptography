#include "interface.h"

feistel_luby_rackoff_c11_err_t feistel_luby_rackoff_c11_verify_guard(bool cond) {
    if (!cond) {
        return FEISTEL_LUBY_RACKOFF_C11_ERR_INVARIANT;
    }
    return FEISTEL_LUBY_RACKOFF_C11_OK;
}
