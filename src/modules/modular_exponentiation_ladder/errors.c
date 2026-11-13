/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder
 */

typedef enum modular_exponentiation_ladder_error_status {
    MODULAR_EXPONENTIATION_LADDER_OK = 0,
    MODULAR_EXPONENTIATION_LADDER_ERR_INVALID_PARAM = -10,
    MODULAR_EXPONENTIATION_LADDER_ERR_CAPACITY_LIMIT = -11,
    MODULAR_EXPONENTIATION_LADDER_ERR_NUMERICAL_FAULT = -12
} modular_exponentiation_ladder_error_status_t;

const char* modular_exponentiation_ladder_error_string(modular_exponentiation_ladder_error_status_t err) {
    switch (err) {
        case MODULAR_EXPONENTIATION_LADDER_OK: return "Operational success";
        case MODULAR_EXPONENTIATION_LADDER_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case MODULAR_EXPONENTIATION_LADDER_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case MODULAR_EXPONENTIATION_LADDER_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
