#ifndef LFSR_GALOIS32_D59_ERRORS_H
#define LFSR_GALOIS32_D59_ERRORS_H

typedef enum lfsr_galois32_d59_err {
    LFSR_GALOIS32_D59_OK = 0,
    LFSR_GALOIS32_D59_ERR_NULL = -1,
    LFSR_GALOIS32_D59_ERR_BOUNDS = -2,
    LFSR_GALOIS32_D59_ERR_INVALID = -3,
    LFSR_GALOIS32_D59_ERR_OVERFLOW = -4,
    LFSR_GALOIS32_D59_ERR_INVARIANT = -5
} lfsr_galois32_d59_err_t;



static inline const char* lfsr_galois32_d59_err_str(lfsr_galois32_d59_err_t err) {
    switch (err) {
        case LFSR_GALOIS32_D59_OK: return "ok";
        case LFSR_GALOIS32_D59_ERR_NULL: return "null pointer supplied";
        case LFSR_GALOIS32_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case LFSR_GALOIS32_D59_ERR_INVALID: return "domain precondition violated";
        case LFSR_GALOIS32_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case LFSR_GALOIS32_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* LFSR_GALOIS32_D59_ERRORS_H */
