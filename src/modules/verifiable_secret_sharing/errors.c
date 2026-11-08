/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

typedef enum verifiable_secret_sharing_error {
    VERIFIABLE_SECRET_SHARING_OK = 0,
    VERIFIABLE_SECRET_SHARING_ERR_NULL = -100,
    VERIFIABLE_SECRET_SHARING_ERR_CAPACITY = -101,
    VERIFIABLE_SECRET_SHARING_ERR_CONVERGENCE = -102
} verifiable_secret_sharing_error_t;

const char* verifiable_secret_sharing_strerror(verifiable_secret_sharing_error_t err) {
    switch (err) {
        case VERIFIABLE_SECRET_SHARING_OK: return "Success";
        case VERIFIABLE_SECRET_SHARING_ERR_NULL: return "Encountered null pointer argument";
        case VERIFIABLE_SECRET_SHARING_ERR_CAPACITY: return "Capacity limit exceeded";
        case VERIFIABLE_SECRET_SHARING_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
