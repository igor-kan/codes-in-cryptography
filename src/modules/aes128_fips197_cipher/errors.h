#ifndef AES128_FIPS197_CIPHER_ERRORS_H
#define AES128_FIPS197_CIPHER_ERRORS_H

typedef enum aes128_fips197_cipher_err {
    AES128_FIPS197_CIPHER_OK = 0,
    AES128_FIPS197_CIPHER_ERR_NULL = -1,
    AES128_FIPS197_CIPHER_ERR_BOUNDS = -2,
    AES128_FIPS197_CIPHER_ERR_INVALID = -3,
    AES128_FIPS197_CIPHER_ERR_OVERFLOW = -4,
    AES128_FIPS197_CIPHER_ERR_INVARIANT = -5
} aes128_fips197_cipher_err_t;



static inline const char* aes128_fips197_cipher_err_str(aes128_fips197_cipher_err_t err) {
    switch (err) {
        case AES128_FIPS197_CIPHER_OK: return "ok";
        case AES128_FIPS197_CIPHER_ERR_NULL: return "null pointer supplied";
        case AES128_FIPS197_CIPHER_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case AES128_FIPS197_CIPHER_ERR_INVALID: return "domain precondition violated";
        case AES128_FIPS197_CIPHER_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case AES128_FIPS197_CIPHER_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* AES128_FIPS197_CIPHER_ERRORS_H */
