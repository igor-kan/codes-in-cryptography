#ifndef CHACHA20_QUARTER_D60_ERRORS_H
#define CHACHA20_QUARTER_D60_ERRORS_H

typedef enum chacha20_quarter_d60_err {
    CHACHA20_QUARTER_D60_OK = 0,
    CHACHA20_QUARTER_D60_ERR_NULL = -1,
    CHACHA20_QUARTER_D60_ERR_BOUNDS = -2,
    CHACHA20_QUARTER_D60_ERR_INVALID = -3,
    CHACHA20_QUARTER_D60_ERR_OVERFLOW = -4,
    CHACHA20_QUARTER_D60_ERR_INVARIANT = -5
} chacha20_quarter_d60_err_t;



static inline const char* chacha20_quarter_d60_err_str(chacha20_quarter_d60_err_t err) {
    switch (err) {
        case CHACHA20_QUARTER_D60_OK: return "ok";
        case CHACHA20_QUARTER_D60_ERR_NULL: return "null pointer supplied";
        case CHACHA20_QUARTER_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CHACHA20_QUARTER_D60_ERR_INVALID: return "domain precondition violated";
        case CHACHA20_QUARTER_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CHACHA20_QUARTER_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CHACHA20_QUARTER_D60_ERRORS_H */
