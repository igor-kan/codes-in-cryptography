#ifndef GF128_GHASH_MUL_D60_ERRORS_H
#define GF128_GHASH_MUL_D60_ERRORS_H

typedef enum gf128_ghash_mul_d60_err {
    GF128_GHASH_MUL_D60_OK = 0,
    GF128_GHASH_MUL_D60_ERR_NULL = -1,
    GF128_GHASH_MUL_D60_ERR_BOUNDS = -2,
    GF128_GHASH_MUL_D60_ERR_INVALID = -3,
    GF128_GHASH_MUL_D60_ERR_OVERFLOW = -4,
    GF128_GHASH_MUL_D60_ERR_INVARIANT = -5
} gf128_ghash_mul_d60_err_t;



static inline const char* gf128_ghash_mul_d60_err_str(gf128_ghash_mul_d60_err_t err) {
    switch (err) {
        case GF128_GHASH_MUL_D60_OK: return "ok";
        case GF128_GHASH_MUL_D60_ERR_NULL: return "null pointer supplied";
        case GF128_GHASH_MUL_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case GF128_GHASH_MUL_D60_ERR_INVALID: return "domain precondition violated";
        case GF128_GHASH_MUL_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case GF128_GHASH_MUL_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* GF128_GHASH_MUL_D60_ERRORS_H */
