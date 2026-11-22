#ifndef HKDF_EXTRACT_EXP_D57_ERRORS_H
#define HKDF_EXTRACT_EXP_D57_ERRORS_H

typedef enum hkdf_extract_exp_d57_err {
    HKDF_EXTRACT_EXP_D57_OK = 0,
    HKDF_EXTRACT_EXP_D57_ERR_NULL = -1,
    HKDF_EXTRACT_EXP_D57_ERR_BOUNDS = -2,
    HKDF_EXTRACT_EXP_D57_ERR_INVALID = -3,
    HKDF_EXTRACT_EXP_D57_ERR_OVERFLOW = -4,
    HKDF_EXTRACT_EXP_D57_ERR_INVARIANT = -5
} hkdf_extract_exp_d57_err_t;



static inline const char* hkdf_extract_exp_d57_err_str(hkdf_extract_exp_d57_err_t err) {
    switch (err) {
        case HKDF_EXTRACT_EXP_D57_OK: return "ok";
        case HKDF_EXTRACT_EXP_D57_ERR_NULL: return "null pointer supplied";
        case HKDF_EXTRACT_EXP_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case HKDF_EXTRACT_EXP_D57_ERR_INVALID: return "domain precondition violated";
        case HKDF_EXTRACT_EXP_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case HKDF_EXTRACT_EXP_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* HKDF_EXTRACT_EXP_D57_ERRORS_H */
