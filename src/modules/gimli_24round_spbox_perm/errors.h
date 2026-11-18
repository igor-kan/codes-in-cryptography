#ifndef GIMLI_24ROUND_SPBOX_PERM_ERRORS_H
#define GIMLI_24ROUND_SPBOX_PERM_ERRORS_H

typedef enum gimli_24round_spbox_perm_err {
    GIMLI_24ROUND_SPBOX_PERM_OK = 0,
    GIMLI_24ROUND_SPBOX_PERM_ERR_NULL = -1,
    GIMLI_24ROUND_SPBOX_PERM_ERR_BOUNDS = -2,
    GIMLI_24ROUND_SPBOX_PERM_ERR_INVALID = -3,
    GIMLI_24ROUND_SPBOX_PERM_ERR_OVERFLOW = -4,
    GIMLI_24ROUND_SPBOX_PERM_ERR_INVARIANT = -5
} gimli_24round_spbox_perm_err_t;



static inline const char* gimli_24round_spbox_perm_err_str(gimli_24round_spbox_perm_err_t err) {
    switch (err) {
        case GIMLI_24ROUND_SPBOX_PERM_OK: return "ok";
        case GIMLI_24ROUND_SPBOX_PERM_ERR_NULL: return "null pointer supplied";
        case GIMLI_24ROUND_SPBOX_PERM_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case GIMLI_24ROUND_SPBOX_PERM_ERR_INVALID: return "domain precondition violated";
        case GIMLI_24ROUND_SPBOX_PERM_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case GIMLI_24ROUND_SPBOX_PERM_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* GIMLI_24ROUND_SPBOX_PERM_ERRORS_H */
