#ifndef XOODYAK_CYCLIST_PERM_ERRORS_H
#define XOODYAK_CYCLIST_PERM_ERRORS_H

typedef enum xoodyak_cyclist_perm_err {
    XOODYAK_CYCLIST_PERM_OK = 0,
    XOODYAK_CYCLIST_PERM_ERR_NULL = -1,
    XOODYAK_CYCLIST_PERM_ERR_BOUNDS = -2,
    XOODYAK_CYCLIST_PERM_ERR_INVALID = -3,
    XOODYAK_CYCLIST_PERM_ERR_OVERFLOW = -4,
    XOODYAK_CYCLIST_PERM_ERR_INVARIANT = -5
} xoodyak_cyclist_perm_err_t;



static inline const char* xoodyak_cyclist_perm_err_str(xoodyak_cyclist_perm_err_t err) {
    switch (err) {
        case XOODYAK_CYCLIST_PERM_OK: return "ok";
        case XOODYAK_CYCLIST_PERM_ERR_NULL: return "null pointer supplied";
        case XOODYAK_CYCLIST_PERM_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XOODYAK_CYCLIST_PERM_ERR_INVALID: return "domain precondition violated";
        case XOODYAK_CYCLIST_PERM_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XOODYAK_CYCLIST_PERM_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XOODYAK_CYCLIST_PERM_ERRORS_H */
