/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr
 */

typedef enum chacha20_block_qr_error_status {
    CHACHA20_BLOCK_QR_OK = 0,
    CHACHA20_BLOCK_QR_ERR_INVALID_PARAM = -10,
    CHACHA20_BLOCK_QR_ERR_CAPACITY_LIMIT = -11,
    CHACHA20_BLOCK_QR_ERR_NUMERICAL_FAULT = -12
} chacha20_block_qr_error_status_t;

const char* chacha20_block_qr_error_string(chacha20_block_qr_error_status_t err) {
    switch (err) {
        case CHACHA20_BLOCK_QR_OK: return "Operational success";
        case CHACHA20_BLOCK_QR_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case CHACHA20_BLOCK_QR_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case CHACHA20_BLOCK_QR_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
