#include "interface.h"

feistel_8round_d59_err_t feistel_8round_d59_validate_len(size_t n) {
    if (n == 0) {
        return FEISTEL_8ROUND_D59_ERR_INVALID;
    }
    return FEISTEL_8ROUND_D59_OK;
}
