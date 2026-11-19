#ifndef ELGAMAL_SCHNORR_ZKP_ERRORS_H
#define ELGAMAL_SCHNORR_ZKP_ERRORS_H

typedef enum elgamal_schnorr_zkp_err {
    ELGAMAL_SCHNORR_ZKP_OK = 0,
    ELGAMAL_SCHNORR_ZKP_ERR_NULL = -1,
    ELGAMAL_SCHNORR_ZKP_ERR_BOUNDS = -2,
    ELGAMAL_SCHNORR_ZKP_ERR_INVALID = -3,
    ELGAMAL_SCHNORR_ZKP_ERR_OVERFLOW = -4,
    ELGAMAL_SCHNORR_ZKP_ERR_INVARIANT = -5
} elgamal_schnorr_zkp_err_t;



static inline const char* elgamal_schnorr_zkp_err_str(elgamal_schnorr_zkp_err_t err) {
    switch (err) {
        case ELGAMAL_SCHNORR_ZKP_OK: return "ok";
        case ELGAMAL_SCHNORR_ZKP_ERR_NULL: return "null pointer supplied";
        case ELGAMAL_SCHNORR_ZKP_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case ELGAMAL_SCHNORR_ZKP_ERR_INVALID: return "domain precondition violated";
        case ELGAMAL_SCHNORR_ZKP_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case ELGAMAL_SCHNORR_ZKP_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* ELGAMAL_SCHNORR_ZKP_ERRORS_H */
