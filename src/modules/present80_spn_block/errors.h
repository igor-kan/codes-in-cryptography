#ifndef PRESENT80_SPN_BLOCK_ERRORS_H
#define PRESENT80_SPN_BLOCK_ERRORS_H

typedef enum present80_spn_block_err {
    PRESENT80_SPN_BLOCK_OK = 0,
    PRESENT80_SPN_BLOCK_ERR_NULL = -1,
    PRESENT80_SPN_BLOCK_ERR_BOUNDS = -2,
    PRESENT80_SPN_BLOCK_ERR_INVALID = -3,
    PRESENT80_SPN_BLOCK_ERR_OVERFLOW = -4,
    PRESENT80_SPN_BLOCK_ERR_INVARIANT = -5
} present80_spn_block_err_t;



static inline const char* present80_spn_block_err_str(present80_spn_block_err_t err) {
    switch (err) {
        case PRESENT80_SPN_BLOCK_OK: return "ok";
        case PRESENT80_SPN_BLOCK_ERR_NULL: return "null pointer supplied";
        case PRESENT80_SPN_BLOCK_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PRESENT80_SPN_BLOCK_ERR_INVALID: return "domain precondition violated";
        case PRESENT80_SPN_BLOCK_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PRESENT80_SPN_BLOCK_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PRESENT80_SPN_BLOCK_ERRORS_H */
