/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Luby-Rackoff 4-Round Balanced Feistel Block Cipher.
 * Module: feistel_cipher_round
 */

typedef enum feistel_cipher_round_error {
    FEISTEL_CIPHER_ROUND_SUCCESS = 0,
    FEISTEL_CIPHER_ROUND_ERR_INVALID_INPUT = -1,
    FEISTEL_CIPHER_ROUND_ERR_BUFFER_OVERFLOW = -2,
    FEISTEL_CIPHER_ROUND_ERR_CONVERGENCE_FAIL = -3
} feistel_cipher_round_error_t;

const char* feistel_cipher_round_str_error(feistel_cipher_round_error_t code) {
    switch (code) {
        case FEISTEL_CIPHER_ROUND_SUCCESS: return "Operation completed successfully";
        case FEISTEL_CIPHER_ROUND_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case FEISTEL_CIPHER_ROUND_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case FEISTEL_CIPHER_ROUND_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
