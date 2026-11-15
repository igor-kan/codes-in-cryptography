#ifndef SALSA20_CORE_STREAM_ERRORS_H
#define SALSA20_CORE_STREAM_ERRORS_H

typedef enum salsa20_core_stream_err {
    SALSA20_CORE_STREAM_OK = 0,
    SALSA20_CORE_STREAM_ERR_NULL = -1,
    SALSA20_CORE_STREAM_ERR_BOUNDS = -2,
    SALSA20_CORE_STREAM_ERR_INVALID = -3,
    SALSA20_CORE_STREAM_ERR_OVERFLOW = -4,
    SALSA20_CORE_STREAM_ERR_INVARIANT = -5
} salsa20_core_stream_err_t;



static inline const char* salsa20_core_stream_err_str(salsa20_core_stream_err_t err) {
    switch (err) {
        case SALSA20_CORE_STREAM_OK: return "ok";
        case SALSA20_CORE_STREAM_ERR_NULL: return "null pointer supplied";
        case SALSA20_CORE_STREAM_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SALSA20_CORE_STREAM_ERR_INVALID: return "domain precondition violated";
        case SALSA20_CORE_STREAM_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SALSA20_CORE_STREAM_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SALSA20_CORE_STREAM_ERRORS_H */
