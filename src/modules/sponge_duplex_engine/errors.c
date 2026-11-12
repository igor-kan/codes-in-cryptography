/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine
 */

typedef enum sponge_duplex_engine_error {
    SPONGE_DUPLEX_ENGINE_SUCCESS = 0,
    SPONGE_DUPLEX_ENGINE_ERR_INVALID_INPUT = -1,
    SPONGE_DUPLEX_ENGINE_ERR_BUFFER_OVERFLOW = -2,
    SPONGE_DUPLEX_ENGINE_ERR_CONVERGENCE_FAIL = -3
} sponge_duplex_engine_error_t;

const char* sponge_duplex_engine_str_error(sponge_duplex_engine_error_t code) {
    switch (code) {
        case SPONGE_DUPLEX_ENGINE_SUCCESS: return "Operation completed successfully";
        case SPONGE_DUPLEX_ENGINE_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case SPONGE_DUPLEX_ENGINE_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case SPONGE_DUPLEX_ENGINE_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
