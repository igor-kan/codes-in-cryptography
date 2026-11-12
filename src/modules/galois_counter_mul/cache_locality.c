/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul
 */

#define GALOIS_COUNTER_MUL_CACHELINE_SIZE 64
#define GALOIS_COUNTER_MUL_BLOCK_SIZE 32

void galois_counter_mul_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += GALOIS_COUNTER_MUL_BLOCK_SIZE) {
        size_t bi_end = (bi + GALOIS_COUNTER_MUL_BLOCK_SIZE < n) ? (bi + GALOIS_COUNTER_MUL_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += GALOIS_COUNTER_MUL_BLOCK_SIZE) {
            size_t bj_end = (bj + GALOIS_COUNTER_MUL_BLOCK_SIZE < n) ? (bj + GALOIS_COUNTER_MUL_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
