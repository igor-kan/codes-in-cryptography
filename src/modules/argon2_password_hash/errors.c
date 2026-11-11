/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Memory-Hard Argon2d/Argon2i Block Mixing Permutation.
 * Module: argon2_password_hash
 */

typedef enum argon2_password_hash_error_code {
    ARGON2_PASSWORD_HASH_STATUS_OK = 0,
    ARGON2_PASSWORD_HASH_ERR_NULL_PTR = -20,
    ARGON2_PASSWORD_HASH_ERR_OUT_OF_BOUNDS = -21,
    ARGON2_PASSWORD_HASH_ERR_DIVERGENCE = -22
} argon2_password_hash_error_code_t;

const char* argon2_password_hash_error_message(argon2_password_hash_error_code_t code) {
    switch (code) {
        case ARGON2_PASSWORD_HASH_STATUS_OK: return "Operational success";
        case ARGON2_PASSWORD_HASH_ERR_NULL_PTR: return "Null pointer argument";
        case ARGON2_PASSWORD_HASH_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case ARGON2_PASSWORD_HASH_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
