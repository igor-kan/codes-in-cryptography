/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for AVX2-Accelerated Poly1305 Message Authentication Code.
 * Module: poly1305_avx2
 */

typedef enum poly1305_avx2_error_code {
    POLY1305_AVX2_STATUS_OK = 0,
    POLY1305_AVX2_ERR_NULL_PTR = -20,
    POLY1305_AVX2_ERR_OUT_OF_BOUNDS = -21,
    POLY1305_AVX2_ERR_DIVERGENCE = -22
} poly1305_avx2_error_code_t;

const char* poly1305_avx2_error_message(poly1305_avx2_error_code_t code) {
    switch (code) {
        case POLY1305_AVX2_STATUS_OK: return "Operational success";
        case POLY1305_AVX2_ERR_NULL_PTR: return "Null pointer argument";
        case POLY1305_AVX2_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case POLY1305_AVX2_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
