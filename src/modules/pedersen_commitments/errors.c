/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

typedef enum pedersen_commitments_error_code {
    PEDERSEN_COMMITMENTS_STATUS_OK = 0,
    PEDERSEN_COMMITMENTS_ERR_NULL_PTR = -10,
    PEDERSEN_COMMITMENTS_ERR_OUT_OF_BOUNDS = -11,
    PEDERSEN_COMMITMENTS_ERR_DIVERGENCE = -12
} pedersen_commitments_error_code_t;

const char* pedersen_commitments_error_message(pedersen_commitments_error_code_t code) {
    switch (code) {
        case PEDERSEN_COMMITMENTS_STATUS_OK: return "Operational success";
        case PEDERSEN_COMMITMENTS_ERR_NULL_PTR: return "Null pointer argument";
        case PEDERSEN_COMMITMENTS_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case PEDERSEN_COMMITMENTS_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
