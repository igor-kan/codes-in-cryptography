#ifndef CHACHA_DRBG_CSPRNG_ERRORS_H
#define CHACHA_DRBG_CSPRNG_ERRORS_H

typedef enum chacha_drbg_csprng_err {
    CHACHA_DRBG_CSPRNG_OK = 0,
    CHACHA_DRBG_CSPRNG_ERR_NULL = -1,
    CHACHA_DRBG_CSPRNG_ERR_BOUNDS = -2,
    CHACHA_DRBG_CSPRNG_ERR_INVALID = -3,
    CHACHA_DRBG_CSPRNG_ERR_OVERFLOW = -4,
    CHACHA_DRBG_CSPRNG_ERR_INVARIANT = -5
} chacha_drbg_csprng_err_t;



static inline const char* chacha_drbg_csprng_err_str(chacha_drbg_csprng_err_t err) {
    switch (err) {
        case CHACHA_DRBG_CSPRNG_OK: return "ok";
        case CHACHA_DRBG_CSPRNG_ERR_NULL: return "null pointer supplied";
        case CHACHA_DRBG_CSPRNG_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CHACHA_DRBG_CSPRNG_ERR_INVALID: return "domain precondition violated";
        case CHACHA_DRBG_CSPRNG_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CHACHA_DRBG_CSPRNG_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CHACHA_DRBG_CSPRNG_ERRORS_H */
