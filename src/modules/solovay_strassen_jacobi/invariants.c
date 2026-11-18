#include "interface.h"

solovay_strassen_jacobi_err_t solovay_strassen_jacobi_verify_guard(bool cond) {
    if (!cond) {
        return SOLOVAY_STRASSEN_JACOBI_ERR_INVARIANT;
    }
    return SOLOVAY_STRASSEN_JACOBI_OK;
}
