#include "interface.h"

rc5_32_12_16_d61_err_t rc5_32_12_16_d61_validate_len(size_t n) {
    if (n == 0) {
        return RC5_32_12_16_D61_ERR_INVALID;
    }
    return RC5_32_12_16_D61_OK;
}
