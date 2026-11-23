#ifndef ECDH_MODP_DH_D58_ERRORS_H
#define ECDH_MODP_DH_D58_ERRORS_H

typedef enum ecdh_modp_dh_d58_err {
    ECDH_MODP_DH_D58_OK = 0,
    ECDH_MODP_DH_D58_ERR_NULL = -1,
    ECDH_MODP_DH_D58_ERR_BOUNDS = -2,
    ECDH_MODP_DH_D58_ERR_INVALID = -3,
    ECDH_MODP_DH_D58_ERR_OVERFLOW = -4,
    ECDH_MODP_DH_D58_ERR_INVARIANT = -5
} ecdh_modp_dh_d58_err_t;



static inline const char* ecdh_modp_dh_d58_err_str(ecdh_modp_dh_d58_err_t err) {
    switch (err) {
        case ECDH_MODP_DH_D58_OK: return "ok";
        case ECDH_MODP_DH_D58_ERR_NULL: return "null pointer supplied";
        case ECDH_MODP_DH_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case ECDH_MODP_DH_D58_ERR_INVALID: return "domain precondition violated";
        case ECDH_MODP_DH_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case ECDH_MODP_DH_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* ECDH_MODP_DH_D58_ERRORS_H */
