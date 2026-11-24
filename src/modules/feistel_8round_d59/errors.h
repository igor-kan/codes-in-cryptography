#ifndef FEISTEL_8ROUND_D59_ERRORS_H
#define FEISTEL_8ROUND_D59_ERRORS_H

typedef enum feistel_8round_d59_err {
    FEISTEL_8ROUND_D59_OK = 0,
    FEISTEL_8ROUND_D59_ERR_NULL = -1,
    FEISTEL_8ROUND_D59_ERR_BOUNDS = -2,
    FEISTEL_8ROUND_D59_ERR_INVALID = -3,
    FEISTEL_8ROUND_D59_ERR_OVERFLOW = -4,
    FEISTEL_8ROUND_D59_ERR_INVARIANT = -5
} feistel_8round_d59_err_t;



static inline const char* feistel_8round_d59_err_str(feistel_8round_d59_err_t err) {
    switch (err) {
        case FEISTEL_8ROUND_D59_OK: return "ok";
        case FEISTEL_8ROUND_D59_ERR_NULL: return "null pointer supplied";
        case FEISTEL_8ROUND_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FEISTEL_8ROUND_D59_ERR_INVALID: return "domain precondition violated";
        case FEISTEL_8ROUND_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FEISTEL_8ROUND_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FEISTEL_8ROUND_D59_ERRORS_H */
