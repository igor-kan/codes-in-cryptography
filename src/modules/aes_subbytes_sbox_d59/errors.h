#ifndef AES_SUBBYTES_SBOX_D59_ERRORS_H
#define AES_SUBBYTES_SBOX_D59_ERRORS_H

typedef enum aes_subbytes_sbox_d59_err {
    AES_SUBBYTES_SBOX_D59_OK = 0,
    AES_SUBBYTES_SBOX_D59_ERR_NULL = -1,
    AES_SUBBYTES_SBOX_D59_ERR_BOUNDS = -2,
    AES_SUBBYTES_SBOX_D59_ERR_INVALID = -3,
    AES_SUBBYTES_SBOX_D59_ERR_OVERFLOW = -4,
    AES_SUBBYTES_SBOX_D59_ERR_INVARIANT = -5
} aes_subbytes_sbox_d59_err_t;



static inline const char* aes_subbytes_sbox_d59_err_str(aes_subbytes_sbox_d59_err_t err) {
    switch (err) {
        case AES_SUBBYTES_SBOX_D59_OK: return "ok";
        case AES_SUBBYTES_SBOX_D59_ERR_NULL: return "null pointer supplied";
        case AES_SUBBYTES_SBOX_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case AES_SUBBYTES_SBOX_D59_ERR_INVALID: return "domain precondition violated";
        case AES_SUBBYTES_SBOX_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case AES_SUBBYTES_SBOX_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* AES_SUBBYTES_SBOX_D59_ERRORS_H */
