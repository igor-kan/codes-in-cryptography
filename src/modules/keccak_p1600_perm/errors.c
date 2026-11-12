/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

typedef enum keccak_p1600_perm_error {
    KECCAK_P1600_PERM_SUCCESS = 0,
    KECCAK_P1600_PERM_ERR_INVALID_INPUT = -1,
    KECCAK_P1600_PERM_ERR_BUFFER_OVERFLOW = -2,
    KECCAK_P1600_PERM_ERR_CONVERGENCE_FAIL = -3
} keccak_p1600_perm_error_t;

const char* keccak_p1600_perm_str_error(keccak_p1600_perm_error_t code) {
    switch (code) {
        case KECCAK_P1600_PERM_SUCCESS: return "Operation completed successfully";
        case KECCAK_P1600_PERM_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case KECCAK_P1600_PERM_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case KECCAK_P1600_PERM_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
