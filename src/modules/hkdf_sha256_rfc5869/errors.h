#ifndef HKDF_SHA256_RFC5869_ERRORS_H
#define HKDF_SHA256_RFC5869_ERRORS_H

typedef enum hkdf_sha256_rfc5869_err {
    HKDF_SHA256_RFC5869_OK = 0,
    HKDF_SHA256_RFC5869_ERR_NULL = -1,
    HKDF_SHA256_RFC5869_ERR_BOUNDS = -2,
    HKDF_SHA256_RFC5869_ERR_INVALID = -3,
    HKDF_SHA256_RFC5869_ERR_OVERFLOW = -4,
    HKDF_SHA256_RFC5869_ERR_INVARIANT = -5
} hkdf_sha256_rfc5869_err_t;



static inline const char* hkdf_sha256_rfc5869_err_str(hkdf_sha256_rfc5869_err_t err) {
    switch (err) {
        case HKDF_SHA256_RFC5869_OK: return "ok";
        case HKDF_SHA256_RFC5869_ERR_NULL: return "null pointer supplied";
        case HKDF_SHA256_RFC5869_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case HKDF_SHA256_RFC5869_ERR_INVALID: return "domain precondition violated";
        case HKDF_SHA256_RFC5869_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case HKDF_SHA256_RFC5869_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* HKDF_SHA256_RFC5869_ERRORS_H */
