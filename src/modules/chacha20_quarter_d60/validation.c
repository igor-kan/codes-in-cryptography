#include "interface.h"

chacha20_quarter_d60_err_t chacha20_quarter_d60_validate_len(size_t n) {
    if (n == 0) {
        return CHACHA20_QUARTER_D60_ERR_INVALID;
    }
    return CHACHA20_QUARTER_D60_OK;
}
