#ifndef FLETCHER64_ADLER32_DUAL_ERRORS_H
#define FLETCHER64_ADLER32_DUAL_ERRORS_H

typedef enum fletcher64_adler32_dual_err {
    FLETCHER64_ADLER32_DUAL_OK = 0,
    FLETCHER64_ADLER32_DUAL_ERR_NULL = -1,
    FLETCHER64_ADLER32_DUAL_ERR_BOUNDS = -2,
    FLETCHER64_ADLER32_DUAL_ERR_INVALID = -3,
    FLETCHER64_ADLER32_DUAL_ERR_OVERFLOW = -4,
    FLETCHER64_ADLER32_DUAL_ERR_INVARIANT = -5
} fletcher64_adler32_dual_err_t;



static inline const char* fletcher64_adler32_dual_err_str(fletcher64_adler32_dual_err_t err) {
    switch (err) {
        case FLETCHER64_ADLER32_DUAL_OK: return "ok";
        case FLETCHER64_ADLER32_DUAL_ERR_NULL: return "null pointer supplied";
        case FLETCHER64_ADLER32_DUAL_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FLETCHER64_ADLER32_DUAL_ERR_INVALID: return "domain precondition violated";
        case FLETCHER64_ADLER32_DUAL_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FLETCHER64_ADLER32_DUAL_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FLETCHER64_ADLER32_DUAL_ERRORS_H */
