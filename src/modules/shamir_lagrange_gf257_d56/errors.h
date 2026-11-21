#ifndef SHAMIR_LAGRANGE_GF257_D56_ERRORS_H
#define SHAMIR_LAGRANGE_GF257_D56_ERRORS_H

typedef enum shamir_lagrange_gf257_d56_err {
    SHAMIR_LAGRANGE_GF257_D56_OK = 0,
    SHAMIR_LAGRANGE_GF257_D56_ERR_NULL = -1,
    SHAMIR_LAGRANGE_GF257_D56_ERR_BOUNDS = -2,
    SHAMIR_LAGRANGE_GF257_D56_ERR_INVALID = -3,
    SHAMIR_LAGRANGE_GF257_D56_ERR_OVERFLOW = -4,
    SHAMIR_LAGRANGE_GF257_D56_ERR_INVARIANT = -5
} shamir_lagrange_gf257_d56_err_t;



static inline const char* shamir_lagrange_gf257_d56_err_str(shamir_lagrange_gf257_d56_err_t err) {
    switch (err) {
        case SHAMIR_LAGRANGE_GF257_D56_OK: return "ok";
        case SHAMIR_LAGRANGE_GF257_D56_ERR_NULL: return "null pointer supplied";
        case SHAMIR_LAGRANGE_GF257_D56_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SHAMIR_LAGRANGE_GF257_D56_ERR_INVALID: return "domain precondition violated";
        case SHAMIR_LAGRANGE_GF257_D56_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SHAMIR_LAGRANGE_GF257_D56_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SHAMIR_LAGRANGE_GF257_D56_ERRORS_H */
