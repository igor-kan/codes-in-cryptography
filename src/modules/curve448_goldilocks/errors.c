/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

typedef enum curve448_goldilocks_error_code {
    CURVE448_GOLDILOCKS_STATUS_OK = 0,
    CURVE448_GOLDILOCKS_ERR_NULL_PTR = -10,
    CURVE448_GOLDILOCKS_ERR_OUT_OF_BOUNDS = -11,
    CURVE448_GOLDILOCKS_ERR_DIVERGENCE = -12
} curve448_goldilocks_error_code_t;

const char* curve448_goldilocks_error_message(curve448_goldilocks_error_code_t code) {
    switch (code) {
        case CURVE448_GOLDILOCKS_STATUS_OK: return "Operational success";
        case CURVE448_GOLDILOCKS_ERR_NULL_PTR: return "Null pointer argument";
        case CURVE448_GOLDILOCKS_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case CURVE448_GOLDILOCKS_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
