#ifndef SPECK64_128_ARX_D57_ERRORS_H
#define SPECK64_128_ARX_D57_ERRORS_H

typedef enum speck64_128_arx_d57_err {
    SPECK64_128_ARX_D57_OK = 0,
    SPECK64_128_ARX_D57_ERR_NULL = -1,
    SPECK64_128_ARX_D57_ERR_BOUNDS = -2,
    SPECK64_128_ARX_D57_ERR_INVALID = -3,
    SPECK64_128_ARX_D57_ERR_OVERFLOW = -4,
    SPECK64_128_ARX_D57_ERR_INVARIANT = -5
} speck64_128_arx_d57_err_t;



static inline const char* speck64_128_arx_d57_err_str(speck64_128_arx_d57_err_t err) {
    switch (err) {
        case SPECK64_128_ARX_D57_OK: return "ok";
        case SPECK64_128_ARX_D57_ERR_NULL: return "null pointer supplied";
        case SPECK64_128_ARX_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SPECK64_128_ARX_D57_ERR_INVALID: return "domain precondition violated";
        case SPECK64_128_ARX_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SPECK64_128_ARX_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SPECK64_128_ARX_D57_ERRORS_H */
