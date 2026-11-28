#include "interface.h"

threefish256_arx_d61_err_t threefish256_arx_d61_validate_len(size_t n) {
    if (n == 0) {
        return THREEFISH256_ARX_D61_ERR_INVALID;
    }
    return THREEFISH256_ARX_D61_OK;
}
