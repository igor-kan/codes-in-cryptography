/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

typedef enum sha256_compression_round_error_status {
    SHA256_COMPRESSION_ROUND_OK = 0,
    SHA256_COMPRESSION_ROUND_ERR_INVALID_PARAM = -10,
    SHA256_COMPRESSION_ROUND_ERR_CAPACITY_LIMIT = -11,
    SHA256_COMPRESSION_ROUND_ERR_NUMERICAL_FAULT = -12
} sha256_compression_round_error_status_t;

const char* sha256_compression_round_error_string(sha256_compression_round_error_status_t err) {
    switch (err) {
        case SHA256_COMPRESSION_ROUND_OK: return "Operational success";
        case SHA256_COMPRESSION_ROUND_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case SHA256_COMPRESSION_ROUND_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case SHA256_COMPRESSION_ROUND_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
