#ifndef SIPHASH_2_4_PRF_D60_ERRORS_H
#define SIPHASH_2_4_PRF_D60_ERRORS_H

typedef enum siphash_2_4_prf_d60_err {
    SIPHASH_2_4_PRF_D60_OK = 0,
    SIPHASH_2_4_PRF_D60_ERR_NULL = -1,
    SIPHASH_2_4_PRF_D60_ERR_BOUNDS = -2,
    SIPHASH_2_4_PRF_D60_ERR_INVALID = -3,
    SIPHASH_2_4_PRF_D60_ERR_OVERFLOW = -4,
    SIPHASH_2_4_PRF_D60_ERR_INVARIANT = -5
} siphash_2_4_prf_d60_err_t;



static inline const char* siphash_2_4_prf_d60_err_str(siphash_2_4_prf_d60_err_t err) {
    switch (err) {
        case SIPHASH_2_4_PRF_D60_OK: return "ok";
        case SIPHASH_2_4_PRF_D60_ERR_NULL: return "null pointer supplied";
        case SIPHASH_2_4_PRF_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SIPHASH_2_4_PRF_D60_ERR_INVALID: return "domain precondition violated";
        case SIPHASH_2_4_PRF_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SIPHASH_2_4_PRF_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SIPHASH_2_4_PRF_D60_ERRORS_H */
