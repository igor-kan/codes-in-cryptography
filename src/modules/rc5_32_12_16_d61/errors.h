#ifndef RC5_32_12_16_D61_ERRORS_H
#define RC5_32_12_16_D61_ERRORS_H

typedef enum rc5_32_12_16_d61_err {
    RC5_32_12_16_D61_OK = 0,
    RC5_32_12_16_D61_ERR_NULL = -1,
    RC5_32_12_16_D61_ERR_BOUNDS = -2,
    RC5_32_12_16_D61_ERR_INVALID = -3,
    RC5_32_12_16_D61_ERR_OVERFLOW = -4,
    RC5_32_12_16_D61_ERR_INVARIANT = -5
} rc5_32_12_16_d61_err_t;



static inline const char* rc5_32_12_16_d61_err_str(rc5_32_12_16_d61_err_t err) {
    switch (err) {
        case RC5_32_12_16_D61_OK: return "ok";
        case RC5_32_12_16_D61_ERR_NULL: return "null pointer supplied";
        case RC5_32_12_16_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RC5_32_12_16_D61_ERR_INVALID: return "domain precondition violated";
        case RC5_32_12_16_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RC5_32_12_16_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RC5_32_12_16_D61_ERRORS_H */
