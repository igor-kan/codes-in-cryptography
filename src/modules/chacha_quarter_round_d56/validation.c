#include "interface.h"

chacha_quarter_round_d56_err_t chacha_quarter_round_d56_validate_len(size_t n) {
    if (n == 0) {
        return CHACHA_QUARTER_ROUND_D56_ERR_INVALID;
    }
    return CHACHA_QUARTER_ROUND_D56_OK;
}
