/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Lagrange Interpolation Secret Reconstruction GF(256).
 * Module: shamir_reconstruction_gf
 */

typedef enum shamir_reconstruction_gf_error_status {
    SHAMIR_RECONSTRUCTION_GF_OK = 0,
    SHAMIR_RECONSTRUCTION_GF_ERR_INVALID_PARAM = -10,
    SHAMIR_RECONSTRUCTION_GF_ERR_CAPACITY_LIMIT = -11,
    SHAMIR_RECONSTRUCTION_GF_ERR_NUMERICAL_FAULT = -12
} shamir_reconstruction_gf_error_status_t;

const char* shamir_reconstruction_gf_error_string(shamir_reconstruction_gf_error_status_t err) {
    switch (err) {
        case SHAMIR_RECONSTRUCTION_GF_OK: return "Operational success";
        case SHAMIR_RECONSTRUCTION_GF_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case SHAMIR_RECONSTRUCTION_GF_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case SHAMIR_RECONSTRUCTION_GF_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
