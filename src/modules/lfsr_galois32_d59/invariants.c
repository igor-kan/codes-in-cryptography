#include "interface.h"

lfsr_galois32_d59_err_t lfsr_galois32_d59_verify_guard(bool cond) {
    if (!cond) {
        return LFSR_GALOIS32_D59_ERR_INVARIANT;
    }
    return LFSR_GALOIS32_D59_OK;
}
