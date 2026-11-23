#include "interface.h"

tea_classic_64_d58_err_t tea_classic_64_d58_validate_len(size_t n) {
    if (n == 0) {
        return TEA_CLASSIC_64_D58_ERR_INVALID;
    }
    return TEA_CLASSIC_64_D58_OK;
}
