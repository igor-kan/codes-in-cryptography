#ifndef MD5_STREAM_DIGEST_D61_ERRORS_H
#define MD5_STREAM_DIGEST_D61_ERRORS_H

typedef enum md5_stream_digest_d61_err {
    MD5_STREAM_DIGEST_D61_OK = 0,
    MD5_STREAM_DIGEST_D61_ERR_NULL = -1,
    MD5_STREAM_DIGEST_D61_ERR_BOUNDS = -2,
    MD5_STREAM_DIGEST_D61_ERR_INVALID = -3,
    MD5_STREAM_DIGEST_D61_ERR_OVERFLOW = -4,
    MD5_STREAM_DIGEST_D61_ERR_INVARIANT = -5
} md5_stream_digest_d61_err_t;



static inline const char* md5_stream_digest_d61_err_str(md5_stream_digest_d61_err_t err) {
    switch (err) {
        case MD5_STREAM_DIGEST_D61_OK: return "ok";
        case MD5_STREAM_DIGEST_D61_ERR_NULL: return "null pointer supplied";
        case MD5_STREAM_DIGEST_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case MD5_STREAM_DIGEST_D61_ERR_INVALID: return "domain precondition violated";
        case MD5_STREAM_DIGEST_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case MD5_STREAM_DIGEST_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* MD5_STREAM_DIGEST_D61_ERRORS_H */
