#ifndef GF256_AES_RIJNDAEL_ERRORS_H
#define GF256_AES_RIJNDAEL_ERRORS_H

typedef enum gf256_aes_rijndael_err {
    GF256_AES_RIJNDAEL_OK = 0,
    GF256_AES_RIJNDAEL_ERR_NULL = -1,
    GF256_AES_RIJNDAEL_ERR_BOUNDS = -2,
    GF256_AES_RIJNDAEL_ERR_INVALID = -3,
    GF256_AES_RIJNDAEL_ERR_OVERFLOW = -4,
    GF256_AES_RIJNDAEL_ERR_INVARIANT = -5
} gf256_aes_rijndael_err_t;



static inline const char* gf256_aes_rijndael_err_str(gf256_aes_rijndael_err_t err) {
    switch (err) {
        case GF256_AES_RIJNDAEL_OK: return "ok";
        case GF256_AES_RIJNDAEL_ERR_NULL: return "null pointer supplied";
        case GF256_AES_RIJNDAEL_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case GF256_AES_RIJNDAEL_ERR_INVALID: return "domain precondition violated";
        case GF256_AES_RIJNDAEL_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case GF256_AES_RIJNDAEL_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* GF256_AES_RIJNDAEL_ERRORS_H */
