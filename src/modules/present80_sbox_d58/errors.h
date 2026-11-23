#ifndef PRESENT80_SBOX_D58_ERRORS_H
#define PRESENT80_SBOX_D58_ERRORS_H

typedef enum present80_sbox_d58_err {
    PRESENT80_SBOX_D58_OK = 0,
    PRESENT80_SBOX_D58_ERR_NULL = -1,
    PRESENT80_SBOX_D58_ERR_BOUNDS = -2,
    PRESENT80_SBOX_D58_ERR_INVALID = -3,
    PRESENT80_SBOX_D58_ERR_OVERFLOW = -4,
    PRESENT80_SBOX_D58_ERR_INVARIANT = -5
} present80_sbox_d58_err_t;



static inline const char* present80_sbox_d58_err_str(present80_sbox_d58_err_t err) {
    switch (err) {
        case PRESENT80_SBOX_D58_OK: return "ok";
        case PRESENT80_SBOX_D58_ERR_NULL: return "null pointer supplied";
        case PRESENT80_SBOX_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PRESENT80_SBOX_D58_ERR_INVALID: return "domain precondition violated";
        case PRESENT80_SBOX_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PRESENT80_SBOX_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PRESENT80_SBOX_D58_ERRORS_H */
