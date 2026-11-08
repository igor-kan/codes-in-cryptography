/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

typedef enum dilithium_poly_mul_error {
    DILITHIUM_POLY_MUL_OK = 0,
    DILITHIUM_POLY_MUL_ERR_NULL = -100,
    DILITHIUM_POLY_MUL_ERR_CAPACITY = -101,
    DILITHIUM_POLY_MUL_ERR_CONVERGENCE = -102
} dilithium_poly_mul_error_t;

const char* dilithium_poly_mul_strerror(dilithium_poly_mul_error_t err) {
    switch (err) {
        case DILITHIUM_POLY_MUL_OK: return "Success";
        case DILITHIUM_POLY_MUL_ERR_NULL: return "Encountered null pointer argument";
        case DILITHIUM_POLY_MUL_ERR_CAPACITY: return "Capacity limit exceeded";
        case DILITHIUM_POLY_MUL_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
