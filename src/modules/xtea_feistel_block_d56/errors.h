#ifndef XTEA_FEISTEL_BLOCK_D56_ERRORS_H
#define XTEA_FEISTEL_BLOCK_D56_ERRORS_H

typedef enum xtea_feistel_block_d56_err {
    XTEA_FEISTEL_BLOCK_D56_OK = 0,
    XTEA_FEISTEL_BLOCK_D56_ERR_NULL = -1,
    XTEA_FEISTEL_BLOCK_D56_ERR_BOUNDS = -2,
    XTEA_FEISTEL_BLOCK_D56_ERR_INVALID = -3,
    XTEA_FEISTEL_BLOCK_D56_ERR_OVERFLOW = -4,
    XTEA_FEISTEL_BLOCK_D56_ERR_INVARIANT = -5
} xtea_feistel_block_d56_err_t;



static inline const char* xtea_feistel_block_d56_err_str(xtea_feistel_block_d56_err_t err) {
    switch (err) {
        case XTEA_FEISTEL_BLOCK_D56_OK: return "ok";
        case XTEA_FEISTEL_BLOCK_D56_ERR_NULL: return "null pointer supplied";
        case XTEA_FEISTEL_BLOCK_D56_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XTEA_FEISTEL_BLOCK_D56_ERR_INVALID: return "domain precondition violated";
        case XTEA_FEISTEL_BLOCK_D56_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XTEA_FEISTEL_BLOCK_D56_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XTEA_FEISTEL_BLOCK_D56_ERRORS_H */
