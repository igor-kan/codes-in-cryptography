#include "interface.h"

lfsr_galois32_d59_err_t lfsr_galois32_d59_validate_len(size_t n) {
    if (n == 0) {
        return LFSR_GALOIS32_D59_ERR_INVALID;
    }
    return LFSR_GALOIS32_D59_OK;
}
