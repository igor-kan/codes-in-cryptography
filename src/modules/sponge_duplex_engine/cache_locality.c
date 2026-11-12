/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine
 */

#define SPONGE_DUPLEX_ENGINE_CACHELINE_SIZE 64
#define SPONGE_DUPLEX_ENGINE_BLOCK_SIZE 32

void sponge_duplex_engine_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += SPONGE_DUPLEX_ENGINE_BLOCK_SIZE) {
        size_t bi_end = (bi + SPONGE_DUPLEX_ENGINE_BLOCK_SIZE < n) ? (bi + SPONGE_DUPLEX_ENGINE_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += SPONGE_DUPLEX_ENGINE_BLOCK_SIZE) {
            size_t bj_end = (bj + SPONGE_DUPLEX_ENGINE_BLOCK_SIZE < n) ? (bj + SPONGE_DUPLEX_ENGINE_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
