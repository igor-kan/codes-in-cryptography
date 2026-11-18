#ifndef RABIN_WILLIAMS_SQRT_TRAP_ERRORS_H
#define RABIN_WILLIAMS_SQRT_TRAP_ERRORS_H

typedef enum rabin_williams_sqrt_trap_err {
    RABIN_WILLIAMS_SQRT_TRAP_OK = 0,
    RABIN_WILLIAMS_SQRT_TRAP_ERR_NULL = -1,
    RABIN_WILLIAMS_SQRT_TRAP_ERR_BOUNDS = -2,
    RABIN_WILLIAMS_SQRT_TRAP_ERR_INVALID = -3,
    RABIN_WILLIAMS_SQRT_TRAP_ERR_OVERFLOW = -4,
    RABIN_WILLIAMS_SQRT_TRAP_ERR_INVARIANT = -5
} rabin_williams_sqrt_trap_err_t;



static inline const char* rabin_williams_sqrt_trap_err_str(rabin_williams_sqrt_trap_err_t err) {
    switch (err) {
        case RABIN_WILLIAMS_SQRT_TRAP_OK: return "ok";
        case RABIN_WILLIAMS_SQRT_TRAP_ERR_NULL: return "null pointer supplied";
        case RABIN_WILLIAMS_SQRT_TRAP_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RABIN_WILLIAMS_SQRT_TRAP_ERR_INVALID: return "domain precondition violated";
        case RABIN_WILLIAMS_SQRT_TRAP_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RABIN_WILLIAMS_SQRT_TRAP_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RABIN_WILLIAMS_SQRT_TRAP_ERRORS_H */
