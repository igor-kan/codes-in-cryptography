/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder
 */

#define POLY1305_CLAMP_LADDER_CACHELINE_SIZE 64
#define POLY1305_CLAMP_LADDER_BLOCK_SIZE 32

void poly1305_clamp_ladder_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += POLY1305_CLAMP_LADDER_BLOCK_SIZE) {
        size_t bi_end = (bi + POLY1305_CLAMP_LADDER_BLOCK_SIZE < n) ? (bi + POLY1305_CLAMP_LADDER_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += POLY1305_CLAMP_LADDER_BLOCK_SIZE) {
            size_t bj_end = (bj + POLY1305_CLAMP_LADDER_BLOCK_SIZE < n) ? (bj + POLY1305_CLAMP_LADDER_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
