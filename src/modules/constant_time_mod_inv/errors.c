/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Constant-Time Modular Inverse via Bernstein-Yang Ladder.
 * Module: constant_time_mod_inv
 */

typedef enum constant_time_mod_inv_error_code {
    CONSTANT_TIME_MOD_INV_STATUS_OK = 0,
    CONSTANT_TIME_MOD_INV_ERR_NULL_PTR = -20,
    CONSTANT_TIME_MOD_INV_ERR_OUT_OF_BOUNDS = -21,
    CONSTANT_TIME_MOD_INV_ERR_DIVERGENCE = -22
} constant_time_mod_inv_error_code_t;

const char* constant_time_mod_inv_error_message(constant_time_mod_inv_error_code_t code) {
    switch (code) {
        case CONSTANT_TIME_MOD_INV_STATUS_OK: return "Operational success";
        case CONSTANT_TIME_MOD_INV_ERR_NULL_PTR: return "Null pointer argument";
        case CONSTANT_TIME_MOD_INV_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case CONSTANT_TIME_MOD_INV_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
