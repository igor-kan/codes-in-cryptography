#include "interface.h"

solovay_strassen_jacobi_err_t solovay_strassen_jacobi_validate_len(size_t n) {
    if (n == 0) {
        return SOLOVAY_STRASSEN_JACOBI_ERR_INVALID;
    }
    return SOLOVAY_STRASSEN_JACOBI_OK;
}
