/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

typedef enum keccak_f1600_theta_error_status {
    KECCAK_F1600_THETA_OK = 0,
    KECCAK_F1600_THETA_ERR_INVALID_PARAM = -10,
    KECCAK_F1600_THETA_ERR_CAPACITY_LIMIT = -11,
    KECCAK_F1600_THETA_ERR_NUMERICAL_FAULT = -12
} keccak_f1600_theta_error_status_t;

const char* keccak_f1600_theta_error_string(keccak_f1600_theta_error_status_t err) {
    switch (err) {
        case KECCAK_F1600_THETA_OK: return "Operational success";
        case KECCAK_F1600_THETA_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case KECCAK_F1600_THETA_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case KECCAK_F1600_THETA_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
