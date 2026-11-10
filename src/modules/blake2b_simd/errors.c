/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for SIMD-Accelerated BLAKE2b Cryptographic Hashing Engine.
 * Module: blake2b_simd
 */

typedef enum blake2b_simd_error_code {
    BLAKE2B_SIMD_STATUS_OK = 0,
    BLAKE2B_SIMD_ERR_NULL_PTR = -10,
    BLAKE2B_SIMD_ERR_OUT_OF_BOUNDS = -11,
    BLAKE2B_SIMD_ERR_DIVERGENCE = -12
} blake2b_simd_error_code_t;

const char* blake2b_simd_error_message(blake2b_simd_error_code_t code) {
    switch (code) {
        case BLAKE2B_SIMD_STATUS_OK: return "Operational success";
        case BLAKE2B_SIMD_ERR_NULL_PTR: return "Null pointer argument";
        case BLAKE2B_SIMD_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case BLAKE2B_SIMD_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
