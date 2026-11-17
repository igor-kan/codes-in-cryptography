#ifndef HCHACHA20_XCHACHA_KDF_ERRORS_H
#define HCHACHA20_XCHACHA_KDF_ERRORS_H

typedef enum hchacha20_xchacha_kdf_err {
    HCHACHA20_XCHACHA_KDF_OK = 0,
    HCHACHA20_XCHACHA_KDF_ERR_NULL = -1,
    HCHACHA20_XCHACHA_KDF_ERR_BOUNDS = -2,
    HCHACHA20_XCHACHA_KDF_ERR_INVALID = -3,
    HCHACHA20_XCHACHA_KDF_ERR_OVERFLOW = -4,
    HCHACHA20_XCHACHA_KDF_ERR_INVARIANT = -5
} hchacha20_xchacha_kdf_err_t;



static inline const char* hchacha20_xchacha_kdf_err_str(hchacha20_xchacha_kdf_err_t err) {
    switch (err) {
        case HCHACHA20_XCHACHA_KDF_OK: return "ok";
        case HCHACHA20_XCHACHA_KDF_ERR_NULL: return "null pointer supplied";
        case HCHACHA20_XCHACHA_KDF_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case HCHACHA20_XCHACHA_KDF_ERR_INVALID: return "domain precondition violated";
        case HCHACHA20_XCHACHA_KDF_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case HCHACHA20_XCHACHA_KDF_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* HCHACHA20_XCHACHA_KDF_ERRORS_H */
