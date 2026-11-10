/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

typedef enum ml_kem_poly_vector_error_code {
    ML_KEM_POLY_VECTOR_STATUS_OK = 0,
    ML_KEM_POLY_VECTOR_ERR_NULL_PTR = -10,
    ML_KEM_POLY_VECTOR_ERR_OUT_OF_BOUNDS = -11,
    ML_KEM_POLY_VECTOR_ERR_DIVERGENCE = -12
} ml_kem_poly_vector_error_code_t;

const char* ml_kem_poly_vector_error_message(ml_kem_poly_vector_error_code_t code) {
    switch (code) {
        case ML_KEM_POLY_VECTOR_STATUS_OK: return "Operational success";
        case ML_KEM_POLY_VECTOR_ERR_NULL_PTR: return "Null pointer argument";
        case ML_KEM_POLY_VECTOR_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case ML_KEM_POLY_VECTOR_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
