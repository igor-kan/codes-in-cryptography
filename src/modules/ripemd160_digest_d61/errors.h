#ifndef RIPEMD160_DIGEST_D61_ERRORS_H
#define RIPEMD160_DIGEST_D61_ERRORS_H

typedef enum ripemd160_digest_d61_err {
    RIPEMD160_DIGEST_D61_OK = 0,
    RIPEMD160_DIGEST_D61_ERR_NULL = -1,
    RIPEMD160_DIGEST_D61_ERR_BOUNDS = -2,
    RIPEMD160_DIGEST_D61_ERR_INVALID = -3,
    RIPEMD160_DIGEST_D61_ERR_OVERFLOW = -4,
    RIPEMD160_DIGEST_D61_ERR_INVARIANT = -5
} ripemd160_digest_d61_err_t;



static inline const char* ripemd160_digest_d61_err_str(ripemd160_digest_d61_err_t err) {
    switch (err) {
        case RIPEMD160_DIGEST_D61_OK: return "ok";
        case RIPEMD160_DIGEST_D61_ERR_NULL: return "null pointer supplied";
        case RIPEMD160_DIGEST_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RIPEMD160_DIGEST_D61_ERR_INVALID: return "domain precondition violated";
        case RIPEMD160_DIGEST_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RIPEMD160_DIGEST_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RIPEMD160_DIGEST_D61_ERRORS_H */
