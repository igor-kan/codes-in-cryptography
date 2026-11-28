#include "interface.h"

rc5_32_12_16_d61_err_t rc5_32_12_16_d61_verify_guard(bool cond) {
    if (!cond) {
        return RC5_32_12_16_D61_ERR_INVARIANT;
    }
    return RC5_32_12_16_D61_OK;
}
