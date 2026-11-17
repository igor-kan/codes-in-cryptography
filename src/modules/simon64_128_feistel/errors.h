#ifndef SIMON64_128_FEISTEL_ERRORS_H
#define SIMON64_128_FEISTEL_ERRORS_H

typedef enum simon64_128_feistel_err {
    SIMON64_128_FEISTEL_OK = 0,
    SIMON64_128_FEISTEL_ERR_NULL = -1,
    SIMON64_128_FEISTEL_ERR_BOUNDS = -2,
    SIMON64_128_FEISTEL_ERR_INVALID = -3,
    SIMON64_128_FEISTEL_ERR_OVERFLOW = -4,
    SIMON64_128_FEISTEL_ERR_INVARIANT = -5
} simon64_128_feistel_err_t;



static inline const char* simon64_128_feistel_err_str(simon64_128_feistel_err_t err) {
    switch (err) {
        case SIMON64_128_FEISTEL_OK: return "ok";
        case SIMON64_128_FEISTEL_ERR_NULL: return "null pointer supplied";
        case SIMON64_128_FEISTEL_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SIMON64_128_FEISTEL_ERR_INVALID: return "domain precondition violated";
        case SIMON64_128_FEISTEL_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SIMON64_128_FEISTEL_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SIMON64_128_FEISTEL_ERRORS_H */
