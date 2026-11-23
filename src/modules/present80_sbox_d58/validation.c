#include "interface.h"

present80_sbox_d58_err_t present80_sbox_d58_validate_len(size_t n) {
    if (n == 0) {
        return PRESENT80_SBOX_D58_ERR_INVALID;
    }
    return PRESENT80_SBOX_D58_OK;
}
