/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

typedef enum x25519_diffie_hellman_error {
    X25519_DIFFIE_HELLMAN_OK = 0,
    X25519_DIFFIE_HELLMAN_ERR_NULL = -100,
    X25519_DIFFIE_HELLMAN_ERR_CAPACITY = -101,
    X25519_DIFFIE_HELLMAN_ERR_CONVERGENCE = -102
} x25519_diffie_hellman_error_t;

const char* x25519_diffie_hellman_strerror(x25519_diffie_hellman_error_t err) {
    switch (err) {
        case X25519_DIFFIE_HELLMAN_OK: return "Success";
        case X25519_DIFFIE_HELLMAN_ERR_NULL: return "Encountered null pointer argument";
        case X25519_DIFFIE_HELLMAN_ERR_CAPACITY: return "Capacity limit exceeded";
        case X25519_DIFFIE_HELLMAN_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
