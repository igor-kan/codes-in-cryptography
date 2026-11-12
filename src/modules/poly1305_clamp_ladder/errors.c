/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder
 */

typedef enum poly1305_clamp_ladder_error {
    POLY1305_CLAMP_LADDER_SUCCESS = 0,
    POLY1305_CLAMP_LADDER_ERR_INVALID_INPUT = -1,
    POLY1305_CLAMP_LADDER_ERR_BUFFER_OVERFLOW = -2,
    POLY1305_CLAMP_LADDER_ERR_CONVERGENCE_FAIL = -3
} poly1305_clamp_ladder_error_t;

const char* poly1305_clamp_ladder_str_error(poly1305_clamp_ladder_error_t code) {
    switch (code) {
        case POLY1305_CLAMP_LADDER_SUCCESS: return "Operation completed successfully";
        case POLY1305_CLAMP_LADDER_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case POLY1305_CLAMP_LADDER_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case POLY1305_CLAMP_LADDER_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
