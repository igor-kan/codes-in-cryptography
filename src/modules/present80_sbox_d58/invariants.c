#include "interface.h"

present80_sbox_d58_err_t present80_sbox_d58_verify_guard(bool cond) {
    if (!cond) {
        return PRESENT80_SBOX_D58_ERR_INVARIANT;
    }
    return PRESENT80_SBOX_D58_OK;
}
