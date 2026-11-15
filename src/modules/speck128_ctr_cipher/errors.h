#ifndef SPECK128_CTR_CIPHER_ERRORS_H
#define SPECK128_CTR_CIPHER_ERRORS_H

typedef enum speck128_ctr_cipher_err {
    SPECK128_CTR_CIPHER_OK = 0,
    SPECK128_CTR_CIPHER_ERR_NULL = -1,
    SPECK128_CTR_CIPHER_ERR_BOUNDS = -2,
    SPECK128_CTR_CIPHER_ERR_INVALID = -3,
    SPECK128_CTR_CIPHER_ERR_OVERFLOW = -4,
    SPECK128_CTR_CIPHER_ERR_INVARIANT = -5
} speck128_ctr_cipher_err_t;



static inline const char* speck128_ctr_cipher_err_str(speck128_ctr_cipher_err_t err) {
    switch (err) {
        case SPECK128_CTR_CIPHER_OK: return "ok";
        case SPECK128_CTR_CIPHER_ERR_NULL: return "null pointer supplied";
        case SPECK128_CTR_CIPHER_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SPECK128_CTR_CIPHER_ERR_INVALID: return "domain precondition violated";
        case SPECK128_CTR_CIPHER_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SPECK128_CTR_CIPHER_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SPECK128_CTR_CIPHER_ERRORS_H */
