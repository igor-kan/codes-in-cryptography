#ifndef FEISTEL_LUBY_RACKOFF_C11_ERRORS_H
#define FEISTEL_LUBY_RACKOFF_C11_ERRORS_H

typedef enum feistel_luby_rackoff_c11_err {
    FEISTEL_LUBY_RACKOFF_C11_OK = 0,
    FEISTEL_LUBY_RACKOFF_C11_ERR_NULL = -1,
    FEISTEL_LUBY_RACKOFF_C11_ERR_BOUNDS = -2,
    FEISTEL_LUBY_RACKOFF_C11_ERR_INVALID = -3,
    FEISTEL_LUBY_RACKOFF_C11_ERR_OVERFLOW = -4,
    FEISTEL_LUBY_RACKOFF_C11_ERR_INVARIANT = -5
} feistel_luby_rackoff_c11_err_t;



static inline const char* feistel_luby_rackoff_c11_err_str(feistel_luby_rackoff_c11_err_t err) {
    switch (err) {
        case FEISTEL_LUBY_RACKOFF_C11_OK: return "ok";
        case FEISTEL_LUBY_RACKOFF_C11_ERR_NULL: return "null pointer supplied";
        case FEISTEL_LUBY_RACKOFF_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FEISTEL_LUBY_RACKOFF_C11_ERR_INVALID: return "domain precondition violated";
        case FEISTEL_LUBY_RACKOFF_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FEISTEL_LUBY_RACKOFF_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FEISTEL_LUBY_RACKOFF_C11_ERRORS_H */
