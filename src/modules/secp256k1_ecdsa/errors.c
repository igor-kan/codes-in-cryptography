/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

typedef enum secp256k1_ecdsa_error_code {
    SECP256K1_ECDSA_STATUS_OK = 0,
    SECP256K1_ECDSA_ERR_NULL_PTR = -20,
    SECP256K1_ECDSA_ERR_OUT_OF_BOUNDS = -21,
    SECP256K1_ECDSA_ERR_DIVERGENCE = -22
} secp256k1_ecdsa_error_code_t;

const char* secp256k1_ecdsa_error_message(secp256k1_ecdsa_error_code_t code) {
    switch (code) {
        case SECP256K1_ECDSA_STATUS_OK: return "Operational success";
        case SECP256K1_ECDSA_ERR_NULL_PTR: return "Null pointer argument";
        case SECP256K1_ECDSA_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case SECP256K1_ECDSA_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
