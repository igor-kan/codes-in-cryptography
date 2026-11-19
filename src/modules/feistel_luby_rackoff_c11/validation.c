#include "interface.h"

feistel_luby_rackoff_c11_err_t feistel_luby_rackoff_c11_validate_len(size_t n) {
    if (n == 0) {
        return FEISTEL_LUBY_RACKOFF_C11_ERR_INVALID;
    }
    return FEISTEL_LUBY_RACKOFF_C11_OK;
}
