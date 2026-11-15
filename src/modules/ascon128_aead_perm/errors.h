#ifndef ASCON128_AEAD_PERM_ERRORS_H
#define ASCON128_AEAD_PERM_ERRORS_H

typedef enum ascon128_aead_perm_err {
    ASCON128_AEAD_PERM_OK = 0,
    ASCON128_AEAD_PERM_ERR_NULL = -1,
    ASCON128_AEAD_PERM_ERR_BOUNDS = -2,
    ASCON128_AEAD_PERM_ERR_INVALID = -3,
    ASCON128_AEAD_PERM_ERR_OVERFLOW = -4,
    ASCON128_AEAD_PERM_ERR_INVARIANT = -5
} ascon128_aead_perm_err_t;



static inline const char* ascon128_aead_perm_err_str(ascon128_aead_perm_err_t err) {
    switch (err) {
        case ASCON128_AEAD_PERM_OK: return "ok";
        case ASCON128_AEAD_PERM_ERR_NULL: return "null pointer supplied";
        case ASCON128_AEAD_PERM_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case ASCON128_AEAD_PERM_ERR_INVALID: return "domain precondition violated";
        case ASCON128_AEAD_PERM_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case ASCON128_AEAD_PERM_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* ASCON128_AEAD_PERM_ERRORS_H */
