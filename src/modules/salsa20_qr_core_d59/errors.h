#ifndef SALSA20_QR_CORE_D59_ERRORS_H
#define SALSA20_QR_CORE_D59_ERRORS_H

typedef enum salsa20_qr_core_d59_err {
    SALSA20_QR_CORE_D59_OK = 0,
    SALSA20_QR_CORE_D59_ERR_NULL = -1,
    SALSA20_QR_CORE_D59_ERR_BOUNDS = -2,
    SALSA20_QR_CORE_D59_ERR_INVALID = -3,
    SALSA20_QR_CORE_D59_ERR_OVERFLOW = -4,
    SALSA20_QR_CORE_D59_ERR_INVARIANT = -5
} salsa20_qr_core_d59_err_t;



static inline const char* salsa20_qr_core_d59_err_str(salsa20_qr_core_d59_err_t err) {
    switch (err) {
        case SALSA20_QR_CORE_D59_OK: return "ok";
        case SALSA20_QR_CORE_D59_ERR_NULL: return "null pointer supplied";
        case SALSA20_QR_CORE_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SALSA20_QR_CORE_D59_ERR_INVALID: return "domain precondition violated";
        case SALSA20_QR_CORE_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SALSA20_QR_CORE_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SALSA20_QR_CORE_D59_ERRORS_H */
