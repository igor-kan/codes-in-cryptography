/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

typedef enum kyber_symmetric_crypto_error_code {
    KYBER_SYMMETRIC_CRYPTO_STATUS_OK = 0,
    KYBER_SYMMETRIC_CRYPTO_ERR_NULL_PTR = -20,
    KYBER_SYMMETRIC_CRYPTO_ERR_OUT_OF_BOUNDS = -21,
    KYBER_SYMMETRIC_CRYPTO_ERR_DIVERGENCE = -22
} kyber_symmetric_crypto_error_code_t;

const char* kyber_symmetric_crypto_error_message(kyber_symmetric_crypto_error_code_t code) {
    switch (code) {
        case KYBER_SYMMETRIC_CRYPTO_STATUS_OK: return "Operational success";
        case KYBER_SYMMETRIC_CRYPTO_ERR_NULL_PTR: return "Null pointer argument";
        case KYBER_SYMMETRIC_CRYPTO_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case KYBER_SYMMETRIC_CRYPTO_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
