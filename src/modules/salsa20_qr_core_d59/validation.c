#include "interface.h"

salsa20_qr_core_d59_err_t salsa20_qr_core_d59_validate_len(size_t n) {
    if (n == 0) {
        return SALSA20_QR_CORE_D59_ERR_INVALID;
    }
    return SALSA20_QR_CORE_D59_OK;
}
