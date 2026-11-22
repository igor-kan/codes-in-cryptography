#include "interface.h"

simon64_128_bit_d57_err_t simon64_128_bit_d57_verify_guard(bool cond) {
    if (!cond) {
        return SIMON64_128_BIT_D57_ERR_INVARIANT;
    }
    return SIMON64_128_BIT_D57_OK;
}
