#ifndef SHA1_RFC3174_COMPAT_ERRORS_H
#define SHA1_RFC3174_COMPAT_ERRORS_H

typedef enum sha1_rfc3174_compat_err {
    SHA1_RFC3174_COMPAT_OK = 0,
    SHA1_RFC3174_COMPAT_ERR_NULL = -1,
    SHA1_RFC3174_COMPAT_ERR_BOUNDS = -2,
    SHA1_RFC3174_COMPAT_ERR_INVALID = -3,
    SHA1_RFC3174_COMPAT_ERR_OVERFLOW = -4,
    SHA1_RFC3174_COMPAT_ERR_INVARIANT = -5
} sha1_rfc3174_compat_err_t;



static inline const char* sha1_rfc3174_compat_err_str(sha1_rfc3174_compat_err_t err) {
    switch (err) {
        case SHA1_RFC3174_COMPAT_OK: return "ok";
        case SHA1_RFC3174_COMPAT_ERR_NULL: return "null pointer supplied";
        case SHA1_RFC3174_COMPAT_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SHA1_RFC3174_COMPAT_ERR_INVALID: return "domain precondition violated";
        case SHA1_RFC3174_COMPAT_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SHA1_RFC3174_COMPAT_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SHA1_RFC3174_COMPAT_ERRORS_H */
