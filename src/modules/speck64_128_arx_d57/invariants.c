#include "interface.h"

speck64_128_arx_d57_err_t speck64_128_arx_d57_verify_guard(bool cond) {
    if (!cond) {
        return SPECK64_128_ARX_D57_ERR_INVARIANT;
    }
    return SPECK64_128_ARX_D57_OK;
}
