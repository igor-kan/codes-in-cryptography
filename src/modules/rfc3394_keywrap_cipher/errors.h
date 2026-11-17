#ifndef RFC3394_KEYWRAP_CIPHER_ERRORS_H
#define RFC3394_KEYWRAP_CIPHER_ERRORS_H

typedef enum rfc3394_keywrap_cipher_err {
    RFC3394_KEYWRAP_CIPHER_OK = 0,
    RFC3394_KEYWRAP_CIPHER_ERR_NULL = -1,
    RFC3394_KEYWRAP_CIPHER_ERR_BOUNDS = -2,
    RFC3394_KEYWRAP_CIPHER_ERR_INVALID = -3,
    RFC3394_KEYWRAP_CIPHER_ERR_OVERFLOW = -4,
    RFC3394_KEYWRAP_CIPHER_ERR_INVARIANT = -5
} rfc3394_keywrap_cipher_err_t;



static inline const char* rfc3394_keywrap_cipher_err_str(rfc3394_keywrap_cipher_err_t err) {
    switch (err) {
        case RFC3394_KEYWRAP_CIPHER_OK: return "ok";
        case RFC3394_KEYWRAP_CIPHER_ERR_NULL: return "null pointer supplied";
        case RFC3394_KEYWRAP_CIPHER_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RFC3394_KEYWRAP_CIPHER_ERR_INVALID: return "domain precondition violated";
        case RFC3394_KEYWRAP_CIPHER_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RFC3394_KEYWRAP_CIPHER_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RFC3394_KEYWRAP_CIPHER_ERRORS_H */
