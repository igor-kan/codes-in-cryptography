#include "interface.h"

salsa20_qr_core_d59_err_t salsa20_qr_core_d59_verify_guard(bool cond) {
    if (!cond) {
        return SALSA20_QR_CORE_D59_ERR_INVARIANT;
    }
    return SALSA20_QR_CORE_D59_OK;
}
