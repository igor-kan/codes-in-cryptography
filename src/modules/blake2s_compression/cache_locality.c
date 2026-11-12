/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression
 */

#define BLAKE2S_COMPRESSION_CACHELINE_SIZE 64
#define BLAKE2S_COMPRESSION_BLOCK_SIZE 32

void blake2s_compression_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += BLAKE2S_COMPRESSION_BLOCK_SIZE) {
        size_t bi_end = (bi + BLAKE2S_COMPRESSION_BLOCK_SIZE < n) ? (bi + BLAKE2S_COMPRESSION_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += BLAKE2S_COMPRESSION_BLOCK_SIZE) {
            size_t bj_end = (bj + BLAKE2S_COMPRESSION_BLOCK_SIZE < n) ? (bj + BLAKE2S_COMPRESSION_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
