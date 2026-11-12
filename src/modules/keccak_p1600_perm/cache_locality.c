/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

#define KECCAK_P1600_PERM_CACHELINE_SIZE 64
#define KECCAK_P1600_PERM_BLOCK_SIZE 32

void keccak_p1600_perm_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += KECCAK_P1600_PERM_BLOCK_SIZE) {
        size_t bi_end = (bi + KECCAK_P1600_PERM_BLOCK_SIZE < n) ? (bi + KECCAK_P1600_PERM_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += KECCAK_P1600_PERM_BLOCK_SIZE) {
            size_t bj_end = (bj + KECCAK_P1600_PERM_BLOCK_SIZE < n) ? (bj + KECCAK_P1600_PERM_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
