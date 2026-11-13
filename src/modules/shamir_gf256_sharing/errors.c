/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing
 */

typedef enum shamir_gf256_sharing_error_status {
    SHAMIR_GF256_SHARING_OK = 0,
    SHAMIR_GF256_SHARING_ERR_INVALID_PARAM = -10,
    SHAMIR_GF256_SHARING_ERR_CAPACITY_LIMIT = -11,
    SHAMIR_GF256_SHARING_ERR_NUMERICAL_FAULT = -12
} shamir_gf256_sharing_error_status_t;

const char* shamir_gf256_sharing_error_string(shamir_gf256_sharing_error_status_t err) {
    switch (err) {
        case SHAMIR_GF256_SHARING_OK: return "Operational success";
        case SHAMIR_GF256_SHARING_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case SHAMIR_GF256_SHARING_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case SHAMIR_GF256_SHARING_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
