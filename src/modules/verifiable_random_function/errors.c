/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

typedef enum verifiable_random_function_error_code {
    VERIFIABLE_RANDOM_FUNCTION_STATUS_OK = 0,
    VERIFIABLE_RANDOM_FUNCTION_ERR_NULL_PTR = -10,
    VERIFIABLE_RANDOM_FUNCTION_ERR_OUT_OF_BOUNDS = -11,
    VERIFIABLE_RANDOM_FUNCTION_ERR_DIVERGENCE = -12
} verifiable_random_function_error_code_t;

const char* verifiable_random_function_error_message(verifiable_random_function_error_code_t code) {
    switch (code) {
        case VERIFIABLE_RANDOM_FUNCTION_STATUS_OK: return "Operational success";
        case VERIFIABLE_RANDOM_FUNCTION_ERR_NULL_PTR: return "Null pointer argument";
        case VERIFIABLE_RANDOM_FUNCTION_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case VERIFIABLE_RANDOM_FUNCTION_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
