#ifndef MODEXP_MONT_LADDER_D57_ERRORS_H
#define MODEXP_MONT_LADDER_D57_ERRORS_H

typedef enum modexp_mont_ladder_d57_err {
    MODEXP_MONT_LADDER_D57_OK = 0,
    MODEXP_MONT_LADDER_D57_ERR_NULL = -1,
    MODEXP_MONT_LADDER_D57_ERR_BOUNDS = -2,
    MODEXP_MONT_LADDER_D57_ERR_INVALID = -3,
    MODEXP_MONT_LADDER_D57_ERR_OVERFLOW = -4,
    MODEXP_MONT_LADDER_D57_ERR_INVARIANT = -5
} modexp_mont_ladder_d57_err_t;



static inline const char* modexp_mont_ladder_d57_err_str(modexp_mont_ladder_d57_err_t err) {
    switch (err) {
        case MODEXP_MONT_LADDER_D57_OK: return "ok";
        case MODEXP_MONT_LADDER_D57_ERR_NULL: return "null pointer supplied";
        case MODEXP_MONT_LADDER_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case MODEXP_MONT_LADDER_D57_ERR_INVALID: return "domain precondition violated";
        case MODEXP_MONT_LADDER_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case MODEXP_MONT_LADDER_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* MODEXP_MONT_LADDER_D57_ERRORS_H */
