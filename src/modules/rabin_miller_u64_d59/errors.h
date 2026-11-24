#ifndef RABIN_MILLER_U64_D59_ERRORS_H
#define RABIN_MILLER_U64_D59_ERRORS_H

typedef enum rabin_miller_u64_d59_err {
    RABIN_MILLER_U64_D59_OK = 0,
    RABIN_MILLER_U64_D59_ERR_NULL = -1,
    RABIN_MILLER_U64_D59_ERR_BOUNDS = -2,
    RABIN_MILLER_U64_D59_ERR_INVALID = -3,
    RABIN_MILLER_U64_D59_ERR_OVERFLOW = -4,
    RABIN_MILLER_U64_D59_ERR_INVARIANT = -5
} rabin_miller_u64_d59_err_t;



static inline const char* rabin_miller_u64_d59_err_str(rabin_miller_u64_d59_err_t err) {
    switch (err) {
        case RABIN_MILLER_U64_D59_OK: return "ok";
        case RABIN_MILLER_U64_D59_ERR_NULL: return "null pointer supplied";
        case RABIN_MILLER_U64_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RABIN_MILLER_U64_D59_ERR_INVALID: return "domain precondition violated";
        case RABIN_MILLER_U64_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RABIN_MILLER_U64_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RABIN_MILLER_U64_D59_ERRORS_H */
