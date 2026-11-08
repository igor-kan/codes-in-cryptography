/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

typedef enum siphash_2_4_error {
    SIPHASH_2_4_OK = 0,
    SIPHASH_2_4_ERR_NULL = -100,
    SIPHASH_2_4_ERR_CAPACITY = -101,
    SIPHASH_2_4_ERR_CONVERGENCE = -102
} siphash_2_4_error_t;

const char* siphash_2_4_strerror(siphash_2_4_error_t err) {
    switch (err) {
        case SIPHASH_2_4_OK: return "Success";
        case SIPHASH_2_4_ERR_NULL: return "Encountered null pointer argument";
        case SIPHASH_2_4_ERR_CAPACITY: return "Capacity limit exceeded";
        case SIPHASH_2_4_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
