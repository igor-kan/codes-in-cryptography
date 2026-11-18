#ifndef RC6_W32_R20_BLOCK_CIPHER_ERRORS_H
#define RC6_W32_R20_BLOCK_CIPHER_ERRORS_H

typedef enum rc6_w32_r20_block_cipher_err {
    RC6_W32_R20_BLOCK_CIPHER_OK = 0,
    RC6_W32_R20_BLOCK_CIPHER_ERR_NULL = -1,
    RC6_W32_R20_BLOCK_CIPHER_ERR_BOUNDS = -2,
    RC6_W32_R20_BLOCK_CIPHER_ERR_INVALID = -3,
    RC6_W32_R20_BLOCK_CIPHER_ERR_OVERFLOW = -4,
    RC6_W32_R20_BLOCK_CIPHER_ERR_INVARIANT = -5
} rc6_w32_r20_block_cipher_err_t;



static inline const char* rc6_w32_r20_block_cipher_err_str(rc6_w32_r20_block_cipher_err_t err) {
    switch (err) {
        case RC6_W32_R20_BLOCK_CIPHER_OK: return "ok";
        case RC6_W32_R20_BLOCK_CIPHER_ERR_NULL: return "null pointer supplied";
        case RC6_W32_R20_BLOCK_CIPHER_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RC6_W32_R20_BLOCK_CIPHER_ERR_INVALID: return "domain precondition violated";
        case RC6_W32_R20_BLOCK_CIPHER_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RC6_W32_R20_BLOCK_CIPHER_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RC6_W32_R20_BLOCK_CIPHER_ERRORS_H */
