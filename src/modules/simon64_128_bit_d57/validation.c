#include "interface.h"

simon64_128_bit_d57_err_t simon64_128_bit_d57_validate_len(size_t n) {
    if (n == 0) {
        return SIMON64_128_BIT_D57_ERR_INVALID;
    }
    return SIMON64_128_BIT_D57_OK;
}
