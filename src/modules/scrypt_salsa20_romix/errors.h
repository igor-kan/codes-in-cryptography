#ifndef SCRYPT_SALSA20_ROMIX_ERRORS_H
#define SCRYPT_SALSA20_ROMIX_ERRORS_H

typedef enum scrypt_salsa20_romix_err {
    SCRYPT_SALSA20_ROMIX_OK = 0,
    SCRYPT_SALSA20_ROMIX_ERR_NULL = -1,
    SCRYPT_SALSA20_ROMIX_ERR_BOUNDS = -2,
    SCRYPT_SALSA20_ROMIX_ERR_INVALID = -3,
    SCRYPT_SALSA20_ROMIX_ERR_OVERFLOW = -4,
    SCRYPT_SALSA20_ROMIX_ERR_INVARIANT = -5
} scrypt_salsa20_romix_err_t;



static inline const char* scrypt_salsa20_romix_err_str(scrypt_salsa20_romix_err_t err) {
    switch (err) {
        case SCRYPT_SALSA20_ROMIX_OK: return "ok";
        case SCRYPT_SALSA20_ROMIX_ERR_NULL: return "null pointer supplied";
        case SCRYPT_SALSA20_ROMIX_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SCRYPT_SALSA20_ROMIX_ERR_INVALID: return "domain precondition violated";
        case SCRYPT_SALSA20_ROMIX_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SCRYPT_SALSA20_ROMIX_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SCRYPT_SALSA20_ROMIX_ERRORS_H */
