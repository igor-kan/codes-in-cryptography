#ifndef PBKDF2_HMAC_KDF_ERRORS_H
#define PBKDF2_HMAC_KDF_ERRORS_H

typedef enum pbkdf2_hmac_kdf_err {
    PBKDF2_HMAC_KDF_OK = 0,
    PBKDF2_HMAC_KDF_ERR_NULL = -1,
    PBKDF2_HMAC_KDF_ERR_BOUNDS = -2,
    PBKDF2_HMAC_KDF_ERR_INVALID = -3,
    PBKDF2_HMAC_KDF_ERR_OVERFLOW = -4,
    PBKDF2_HMAC_KDF_ERR_INVARIANT = -5
} pbkdf2_hmac_kdf_err_t;



static inline const char* pbkdf2_hmac_kdf_err_str(pbkdf2_hmac_kdf_err_t err) {
    switch (err) {
        case PBKDF2_HMAC_KDF_OK: return "ok";
        case PBKDF2_HMAC_KDF_ERR_NULL: return "null pointer supplied";
        case PBKDF2_HMAC_KDF_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PBKDF2_HMAC_KDF_ERR_INVALID: return "domain precondition violated";
        case PBKDF2_HMAC_KDF_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PBKDF2_HMAC_KDF_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PBKDF2_HMAC_KDF_ERRORS_H */
