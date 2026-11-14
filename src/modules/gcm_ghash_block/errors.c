/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block
 */

typedef enum gcm_ghash_block_error_status {
    GCM_GHASH_BLOCK_OK = 0,
    GCM_GHASH_BLOCK_ERR_INVALID_PARAM = -10,
    GCM_GHASH_BLOCK_ERR_CAPACITY_LIMIT = -11,
    GCM_GHASH_BLOCK_ERR_NUMERICAL_FAULT = -12
} gcm_ghash_block_error_status_t;

const char* gcm_ghash_block_error_string(gcm_ghash_block_error_status_t err) {
    switch (err) {
        case GCM_GHASH_BLOCK_OK: return "Operational success";
        case GCM_GHASH_BLOCK_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case GCM_GHASH_BLOCK_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case GCM_GHASH_BLOCK_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
