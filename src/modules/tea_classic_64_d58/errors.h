#ifndef TEA_CLASSIC_64_D58_ERRORS_H
#define TEA_CLASSIC_64_D58_ERRORS_H

typedef enum tea_classic_64_d58_err {
    TEA_CLASSIC_64_D58_OK = 0,
    TEA_CLASSIC_64_D58_ERR_NULL = -1,
    TEA_CLASSIC_64_D58_ERR_BOUNDS = -2,
    TEA_CLASSIC_64_D58_ERR_INVALID = -3,
    TEA_CLASSIC_64_D58_ERR_OVERFLOW = -4,
    TEA_CLASSIC_64_D58_ERR_INVARIANT = -5
} tea_classic_64_d58_err_t;



static inline const char* tea_classic_64_d58_err_str(tea_classic_64_d58_err_t err) {
    switch (err) {
        case TEA_CLASSIC_64_D58_OK: return "ok";
        case TEA_CLASSIC_64_D58_ERR_NULL: return "null pointer supplied";
        case TEA_CLASSIC_64_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case TEA_CLASSIC_64_D58_ERR_INVALID: return "domain precondition violated";
        case TEA_CLASSIC_64_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case TEA_CLASSIC_64_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* TEA_CLASSIC_64_D58_ERRORS_H */
