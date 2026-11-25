#ifndef FE25519_ARITH_D60_ERRORS_H
#define FE25519_ARITH_D60_ERRORS_H

typedef enum fe25519_arith_d60_err {
    FE25519_ARITH_D60_OK = 0,
    FE25519_ARITH_D60_ERR_NULL = -1,
    FE25519_ARITH_D60_ERR_BOUNDS = -2,
    FE25519_ARITH_D60_ERR_INVALID = -3,
    FE25519_ARITH_D60_ERR_OVERFLOW = -4,
    FE25519_ARITH_D60_ERR_INVARIANT = -5
} fe25519_arith_d60_err_t;



static inline const char* fe25519_arith_d60_err_str(fe25519_arith_d60_err_t err) {
    switch (err) {
        case FE25519_ARITH_D60_OK: return "ok";
        case FE25519_ARITH_D60_ERR_NULL: return "null pointer supplied";
        case FE25519_ARITH_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FE25519_ARITH_D60_ERR_INVALID: return "domain precondition violated";
        case FE25519_ARITH_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FE25519_ARITH_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FE25519_ARITH_D60_ERRORS_H */
