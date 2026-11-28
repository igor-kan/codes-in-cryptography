#ifndef THREEFISH256_ARX_D61_ERRORS_H
#define THREEFISH256_ARX_D61_ERRORS_H

typedef enum threefish256_arx_d61_err {
    THREEFISH256_ARX_D61_OK = 0,
    THREEFISH256_ARX_D61_ERR_NULL = -1,
    THREEFISH256_ARX_D61_ERR_BOUNDS = -2,
    THREEFISH256_ARX_D61_ERR_INVALID = -3,
    THREEFISH256_ARX_D61_ERR_OVERFLOW = -4,
    THREEFISH256_ARX_D61_ERR_INVARIANT = -5
} threefish256_arx_d61_err_t;



static inline const char* threefish256_arx_d61_err_str(threefish256_arx_d61_err_t err) {
    switch (err) {
        case THREEFISH256_ARX_D61_OK: return "ok";
        case THREEFISH256_ARX_D61_ERR_NULL: return "null pointer supplied";
        case THREEFISH256_ARX_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case THREEFISH256_ARX_D61_ERR_INVALID: return "domain precondition violated";
        case THREEFISH256_ARX_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case THREEFISH256_ARX_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* THREEFISH256_ARX_D61_ERRORS_H */
