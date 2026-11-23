#ifndef GCM_GHASH_GF128_D58_ERRORS_H
#define GCM_GHASH_GF128_D58_ERRORS_H

typedef enum gcm_ghash_gf128_d58_err {
    GCM_GHASH_GF128_D58_OK = 0,
    GCM_GHASH_GF128_D58_ERR_NULL = -1,
    GCM_GHASH_GF128_D58_ERR_BOUNDS = -2,
    GCM_GHASH_GF128_D58_ERR_INVALID = -3,
    GCM_GHASH_GF128_D58_ERR_OVERFLOW = -4,
    GCM_GHASH_GF128_D58_ERR_INVARIANT = -5
} gcm_ghash_gf128_d58_err_t;



static inline const char* gcm_ghash_gf128_d58_err_str(gcm_ghash_gf128_d58_err_t err) {
    switch (err) {
        case GCM_GHASH_GF128_D58_OK: return "ok";
        case GCM_GHASH_GF128_D58_ERR_NULL: return "null pointer supplied";
        case GCM_GHASH_GF128_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case GCM_GHASH_GF128_D58_ERR_INVALID: return "domain precondition violated";
        case GCM_GHASH_GF128_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case GCM_GHASH_GF128_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* GCM_GHASH_GF128_D58_ERRORS_H */
