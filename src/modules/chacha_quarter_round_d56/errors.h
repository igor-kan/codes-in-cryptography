#ifndef CHACHA_QUARTER_ROUND_D56_ERRORS_H
#define CHACHA_QUARTER_ROUND_D56_ERRORS_H

typedef enum chacha_quarter_round_d56_err {
    CHACHA_QUARTER_ROUND_D56_OK = 0,
    CHACHA_QUARTER_ROUND_D56_ERR_NULL = -1,
    CHACHA_QUARTER_ROUND_D56_ERR_BOUNDS = -2,
    CHACHA_QUARTER_ROUND_D56_ERR_INVALID = -3,
    CHACHA_QUARTER_ROUND_D56_ERR_OVERFLOW = -4,
    CHACHA_QUARTER_ROUND_D56_ERR_INVARIANT = -5
} chacha_quarter_round_d56_err_t;



static inline const char* chacha_quarter_round_d56_err_str(chacha_quarter_round_d56_err_t err) {
    switch (err) {
        case CHACHA_QUARTER_ROUND_D56_OK: return "ok";
        case CHACHA_QUARTER_ROUND_D56_ERR_NULL: return "null pointer supplied";
        case CHACHA_QUARTER_ROUND_D56_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CHACHA_QUARTER_ROUND_D56_ERR_INVALID: return "domain precondition violated";
        case CHACHA_QUARTER_ROUND_D56_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CHACHA_QUARTER_ROUND_D56_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CHACHA_QUARTER_ROUND_D56_ERRORS_H */
