/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

typedef enum bls12_381_pairing_error_code {
    BLS12_381_PAIRING_STATUS_OK = 0,
    BLS12_381_PAIRING_ERR_NULL_PTR = -20,
    BLS12_381_PAIRING_ERR_OUT_OF_BOUNDS = -21,
    BLS12_381_PAIRING_ERR_DIVERGENCE = -22
} bls12_381_pairing_error_code_t;

const char* bls12_381_pairing_error_message(bls12_381_pairing_error_code_t code) {
    switch (code) {
        case BLS12_381_PAIRING_STATUS_OK: return "Operational success";
        case BLS12_381_PAIRING_ERR_NULL_PTR: return "Null pointer argument";
        case BLS12_381_PAIRING_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case BLS12_381_PAIRING_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
