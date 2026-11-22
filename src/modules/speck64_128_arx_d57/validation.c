#include "interface.h"

speck64_128_arx_d57_err_t speck64_128_arx_d57_validate_len(size_t n) {
    if (n == 0) {
        return SPECK64_128_ARX_D57_ERR_INVALID;
    }
    return SPECK64_128_ARX_D57_OK;
}
