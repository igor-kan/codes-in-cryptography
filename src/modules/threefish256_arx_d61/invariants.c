#include "interface.h"

threefish256_arx_d61_err_t threefish256_arx_d61_verify_guard(bool cond) {
    if (!cond) {
        return THREEFISH256_ARX_D61_ERR_INVARIANT;
    }
    return THREEFISH256_ARX_D61_OK;
}
