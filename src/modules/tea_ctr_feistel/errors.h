#ifndef TEA_CTR_FEISTEL_ERRORS_H
#define TEA_CTR_FEISTEL_ERRORS_H

typedef enum tea_ctr_feistel_err {
    TEA_CTR_FEISTEL_OK = 0,
    TEA_CTR_FEISTEL_ERR_NULL = -1,
    TEA_CTR_FEISTEL_ERR_BOUNDS = -2,
    TEA_CTR_FEISTEL_ERR_INVALID = -3,
    TEA_CTR_FEISTEL_ERR_OVERFLOW = -4,
    TEA_CTR_FEISTEL_ERR_INVARIANT = -5
} tea_ctr_feistel_err_t;



static inline const char* tea_ctr_feistel_err_str(tea_ctr_feistel_err_t err) {
    switch (err) {
        case TEA_CTR_FEISTEL_OK: return "ok";
        case TEA_CTR_FEISTEL_ERR_NULL: return "null pointer supplied";
        case TEA_CTR_FEISTEL_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case TEA_CTR_FEISTEL_ERR_INVALID: return "domain precondition violated";
        case TEA_CTR_FEISTEL_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case TEA_CTR_FEISTEL_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* TEA_CTR_FEISTEL_ERRORS_H */
