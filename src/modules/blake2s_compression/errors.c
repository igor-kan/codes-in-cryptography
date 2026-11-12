/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression
 */

typedef enum blake2s_compression_error {
    BLAKE2S_COMPRESSION_SUCCESS = 0,
    BLAKE2S_COMPRESSION_ERR_INVALID_INPUT = -1,
    BLAKE2S_COMPRESSION_ERR_BUFFER_OVERFLOW = -2,
    BLAKE2S_COMPRESSION_ERR_CONVERGENCE_FAIL = -3
} blake2s_compression_error_t;

const char* blake2s_compression_str_error(blake2s_compression_error_t code) {
    switch (code) {
        case BLAKE2S_COMPRESSION_SUCCESS: return "Operation completed successfully";
        case BLAKE2S_COMPRESSION_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case BLAKE2S_COMPRESSION_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case BLAKE2S_COMPRESSION_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
