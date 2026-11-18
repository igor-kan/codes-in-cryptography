#ifndef SOLOVAY_STRASSEN_JACOBI_ERRORS_H
#define SOLOVAY_STRASSEN_JACOBI_ERRORS_H

typedef enum solovay_strassen_jacobi_err {
    SOLOVAY_STRASSEN_JACOBI_OK = 0,
    SOLOVAY_STRASSEN_JACOBI_ERR_NULL = -1,
    SOLOVAY_STRASSEN_JACOBI_ERR_BOUNDS = -2,
    SOLOVAY_STRASSEN_JACOBI_ERR_INVALID = -3,
    SOLOVAY_STRASSEN_JACOBI_ERR_OVERFLOW = -4,
    SOLOVAY_STRASSEN_JACOBI_ERR_INVARIANT = -5
} solovay_strassen_jacobi_err_t;



static inline const char* solovay_strassen_jacobi_err_str(solovay_strassen_jacobi_err_t err) {
    switch (err) {
        case SOLOVAY_STRASSEN_JACOBI_OK: return "ok";
        case SOLOVAY_STRASSEN_JACOBI_ERR_NULL: return "null pointer supplied";
        case SOLOVAY_STRASSEN_JACOBI_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SOLOVAY_STRASSEN_JACOBI_ERR_INVALID: return "domain precondition violated";
        case SOLOVAY_STRASSEN_JACOBI_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SOLOVAY_STRASSEN_JACOBI_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SOLOVAY_STRASSEN_JACOBI_ERRORS_H */
