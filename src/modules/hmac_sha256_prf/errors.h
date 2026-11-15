#ifndef HMAC_SHA256_PRF_ERRORS_H
#define HMAC_SHA256_PRF_ERRORS_H

typedef enum hmac_sha256_prf_err {
    HMAC_SHA256_PRF_OK = 0,
    HMAC_SHA256_PRF_ERR_NULL = -1,
    HMAC_SHA256_PRF_ERR_BOUNDS = -2,
    HMAC_SHA256_PRF_ERR_INVALID = -3,
    HMAC_SHA256_PRF_ERR_OVERFLOW = -4,
    HMAC_SHA256_PRF_ERR_INVARIANT = -5
} hmac_sha256_prf_err_t;



static inline const char* hmac_sha256_prf_err_str(hmac_sha256_prf_err_t err) {
    switch (err) {
        case HMAC_SHA256_PRF_OK: return "ok";
        case HMAC_SHA256_PRF_ERR_NULL: return "null pointer supplied";
        case HMAC_SHA256_PRF_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case HMAC_SHA256_PRF_ERR_INVALID: return "domain precondition violated";
        case HMAC_SHA256_PRF_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case HMAC_SHA256_PRF_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* HMAC_SHA256_PRF_ERRORS_H */
