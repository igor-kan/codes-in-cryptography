/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

typedef enum aes_gcm_gfmul_error {
    AES_GCM_GFMUL_OK = 0,
    AES_GCM_GFMUL_ERR_NULL = -100,
    AES_GCM_GFMUL_ERR_CAPACITY = -101,
    AES_GCM_GFMUL_ERR_CONVERGENCE = -102
} aes_gcm_gfmul_error_t;

const char* aes_gcm_gfmul_strerror(aes_gcm_gfmul_error_t err) {
    switch (err) {
        case AES_GCM_GFMUL_OK: return "Success";
        case AES_GCM_GFMUL_ERR_NULL: return "Encountered null pointer argument";
        case AES_GCM_GFMUL_ERR_CAPACITY: return "Capacity limit exceeded";
        case AES_GCM_GFMUL_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
