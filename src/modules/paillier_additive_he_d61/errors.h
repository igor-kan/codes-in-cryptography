#ifndef PAILLIER_ADDITIVE_HE_D61_ERRORS_H
#define PAILLIER_ADDITIVE_HE_D61_ERRORS_H

typedef enum paillier_additive_he_d61_err {
    PAILLIER_ADDITIVE_HE_D61_OK = 0,
    PAILLIER_ADDITIVE_HE_D61_ERR_NULL = -1,
    PAILLIER_ADDITIVE_HE_D61_ERR_BOUNDS = -2,
    PAILLIER_ADDITIVE_HE_D61_ERR_INVALID = -3,
    PAILLIER_ADDITIVE_HE_D61_ERR_OVERFLOW = -4,
    PAILLIER_ADDITIVE_HE_D61_ERR_INVARIANT = -5
} paillier_additive_he_d61_err_t;



static inline const char* paillier_additive_he_d61_err_str(paillier_additive_he_d61_err_t err) {
    switch (err) {
        case PAILLIER_ADDITIVE_HE_D61_OK: return "ok";
        case PAILLIER_ADDITIVE_HE_D61_ERR_NULL: return "null pointer supplied";
        case PAILLIER_ADDITIVE_HE_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PAILLIER_ADDITIVE_HE_D61_ERR_INVALID: return "domain precondition violated";
        case PAILLIER_ADDITIVE_HE_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PAILLIER_ADDITIVE_HE_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PAILLIER_ADDITIVE_HE_D61_ERRORS_H */
