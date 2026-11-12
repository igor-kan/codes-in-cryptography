/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul
 */

typedef enum galois_counter_mul_error {
    GALOIS_COUNTER_MUL_SUCCESS = 0,
    GALOIS_COUNTER_MUL_ERR_INVALID_INPUT = -1,
    GALOIS_COUNTER_MUL_ERR_BUFFER_OVERFLOW = -2,
    GALOIS_COUNTER_MUL_ERR_CONVERGENCE_FAIL = -3
} galois_counter_mul_error_t;

const char* galois_counter_mul_str_error(galois_counter_mul_error_t code) {
    switch (code) {
        case GALOIS_COUNTER_MUL_SUCCESS: return "Operation completed successfully";
        case GALOIS_COUNTER_MUL_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case GALOIS_COUNTER_MUL_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case GALOIS_COUNTER_MUL_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
