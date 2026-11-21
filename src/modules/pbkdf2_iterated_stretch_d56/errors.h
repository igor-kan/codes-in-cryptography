#ifndef PBKDF2_ITERATED_STRETCH_D56_ERRORS_H
#define PBKDF2_ITERATED_STRETCH_D56_ERRORS_H

typedef enum pbkdf2_iterated_stretch_d56_err {
    PBKDF2_ITERATED_STRETCH_D56_OK = 0,
    PBKDF2_ITERATED_STRETCH_D56_ERR_NULL = -1,
    PBKDF2_ITERATED_STRETCH_D56_ERR_BOUNDS = -2,
    PBKDF2_ITERATED_STRETCH_D56_ERR_INVALID = -3,
    PBKDF2_ITERATED_STRETCH_D56_ERR_OVERFLOW = -4,
    PBKDF2_ITERATED_STRETCH_D56_ERR_INVARIANT = -5
} pbkdf2_iterated_stretch_d56_err_t;



static inline const char* pbkdf2_iterated_stretch_d56_err_str(pbkdf2_iterated_stretch_d56_err_t err) {
    switch (err) {
        case PBKDF2_ITERATED_STRETCH_D56_OK: return "ok";
        case PBKDF2_ITERATED_STRETCH_D56_ERR_NULL: return "null pointer supplied";
        case PBKDF2_ITERATED_STRETCH_D56_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PBKDF2_ITERATED_STRETCH_D56_ERR_INVALID: return "domain precondition violated";
        case PBKDF2_ITERATED_STRETCH_D56_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PBKDF2_ITERATED_STRETCH_D56_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PBKDF2_ITERATED_STRETCH_D56_ERRORS_H */
