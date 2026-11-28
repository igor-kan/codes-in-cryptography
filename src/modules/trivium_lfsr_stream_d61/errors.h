#ifndef TRIVIUM_LFSR_STREAM_D61_ERRORS_H
#define TRIVIUM_LFSR_STREAM_D61_ERRORS_H

typedef enum trivium_lfsr_stream_d61_err {
    TRIVIUM_LFSR_STREAM_D61_OK = 0,
    TRIVIUM_LFSR_STREAM_D61_ERR_NULL = -1,
    TRIVIUM_LFSR_STREAM_D61_ERR_BOUNDS = -2,
    TRIVIUM_LFSR_STREAM_D61_ERR_INVALID = -3,
    TRIVIUM_LFSR_STREAM_D61_ERR_OVERFLOW = -4,
    TRIVIUM_LFSR_STREAM_D61_ERR_INVARIANT = -5
} trivium_lfsr_stream_d61_err_t;



static inline const char* trivium_lfsr_stream_d61_err_str(trivium_lfsr_stream_d61_err_t err) {
    switch (err) {
        case TRIVIUM_LFSR_STREAM_D61_OK: return "ok";
        case TRIVIUM_LFSR_STREAM_D61_ERR_NULL: return "null pointer supplied";
        case TRIVIUM_LFSR_STREAM_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case TRIVIUM_LFSR_STREAM_D61_ERR_INVALID: return "domain precondition violated";
        case TRIVIUM_LFSR_STREAM_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case TRIVIUM_LFSR_STREAM_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* TRIVIUM_LFSR_STREAM_D61_ERRORS_H */
