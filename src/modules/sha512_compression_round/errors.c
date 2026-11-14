/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round
 */

typedef enum sha512_compression_round_error_status {
    SHA512_COMPRESSION_ROUND_OK = 0,
    SHA512_COMPRESSION_ROUND_ERR_INVALID_PARAM = -10,
    SHA512_COMPRESSION_ROUND_ERR_CAPACITY_LIMIT = -11,
    SHA512_COMPRESSION_ROUND_ERR_NUMERICAL_FAULT = -12
} sha512_compression_round_error_status_t;

const char* sha512_compression_round_error_string(sha512_compression_round_error_status_t err) {
    switch (err) {
        case SHA512_COMPRESSION_ROUND_OK: return "Operational success";
        case SHA512_COMPRESSION_ROUND_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case SHA512_COMPRESSION_ROUND_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case SHA512_COMPRESSION_ROUND_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
