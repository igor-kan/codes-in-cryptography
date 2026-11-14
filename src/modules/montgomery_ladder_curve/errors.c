/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Montgomery Ladder Scalar Multiplication on Curves.
 * Module: montgomery_ladder_curve
 */

typedef enum montgomery_ladder_curve_error_status {
    MONTGOMERY_LADDER_CURVE_OK = 0,
    MONTGOMERY_LADDER_CURVE_ERR_INVALID_PARAM = -10,
    MONTGOMERY_LADDER_CURVE_ERR_CAPACITY_LIMIT = -11,
    MONTGOMERY_LADDER_CURVE_ERR_NUMERICAL_FAULT = -12
} montgomery_ladder_curve_error_status_t;

const char* montgomery_ladder_curve_error_string(montgomery_ladder_curve_error_status_t err) {
    switch (err) {
        case MONTGOMERY_LADDER_CURVE_OK: return "Operational success";
        case MONTGOMERY_LADDER_CURVE_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case MONTGOMERY_LADDER_CURVE_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case MONTGOMERY_LADDER_CURVE_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
