#ifndef ELGAMAL_MULTIPLICATIVE_HOM_ERRORS_H
#define ELGAMAL_MULTIPLICATIVE_HOM_ERRORS_H

typedef enum elgamal_multiplicative_hom_err {
    ELGAMAL_MULTIPLICATIVE_HOM_OK = 0,
    ELGAMAL_MULTIPLICATIVE_HOM_ERR_NULL = -1,
    ELGAMAL_MULTIPLICATIVE_HOM_ERR_BOUNDS = -2,
    ELGAMAL_MULTIPLICATIVE_HOM_ERR_INVALID = -3,
    ELGAMAL_MULTIPLICATIVE_HOM_ERR_OVERFLOW = -4,
    ELGAMAL_MULTIPLICATIVE_HOM_ERR_INVARIANT = -5
} elgamal_multiplicative_hom_err_t;



static inline const char* elgamal_multiplicative_hom_err_str(elgamal_multiplicative_hom_err_t err) {
    switch (err) {
        case ELGAMAL_MULTIPLICATIVE_HOM_OK: return "ok";
        case ELGAMAL_MULTIPLICATIVE_HOM_ERR_NULL: return "null pointer supplied";
        case ELGAMAL_MULTIPLICATIVE_HOM_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case ELGAMAL_MULTIPLICATIVE_HOM_ERR_INVALID: return "domain precondition violated";
        case ELGAMAL_MULTIPLICATIVE_HOM_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case ELGAMAL_MULTIPLICATIVE_HOM_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* ELGAMAL_MULTIPLICATIVE_HOM_ERRORS_H */
