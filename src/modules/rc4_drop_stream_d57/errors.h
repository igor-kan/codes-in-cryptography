#ifndef RC4_DROP_STREAM_D57_ERRORS_H
#define RC4_DROP_STREAM_D57_ERRORS_H

typedef enum rc4_drop_stream_d57_err {
    RC4_DROP_STREAM_D57_OK = 0,
    RC4_DROP_STREAM_D57_ERR_NULL = -1,
    RC4_DROP_STREAM_D57_ERR_BOUNDS = -2,
    RC4_DROP_STREAM_D57_ERR_INVALID = -3,
    RC4_DROP_STREAM_D57_ERR_OVERFLOW = -4,
    RC4_DROP_STREAM_D57_ERR_INVARIANT = -5
} rc4_drop_stream_d57_err_t;



static inline const char* rc4_drop_stream_d57_err_str(rc4_drop_stream_d57_err_t err) {
    switch (err) {
        case RC4_DROP_STREAM_D57_OK: return "ok";
        case RC4_DROP_STREAM_D57_ERR_NULL: return "null pointer supplied";
        case RC4_DROP_STREAM_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RC4_DROP_STREAM_D57_ERR_INVALID: return "domain precondition violated";
        case RC4_DROP_STREAM_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RC4_DROP_STREAM_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RC4_DROP_STREAM_D57_ERRORS_H */
