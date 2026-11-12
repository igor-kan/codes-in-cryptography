/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Luby-Rackoff 4-Round Balanced Feistel Block Cipher.
 * Module: feistel_cipher_round
 */

#define FEISTEL_CIPHER_ROUND_CACHELINE_SIZE 64
#define FEISTEL_CIPHER_ROUND_BLOCK_SIZE 32

void feistel_cipher_round_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += FEISTEL_CIPHER_ROUND_BLOCK_SIZE) {
        size_t bi_end = (bi + FEISTEL_CIPHER_ROUND_BLOCK_SIZE < n) ? (bi + FEISTEL_CIPHER_ROUND_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += FEISTEL_CIPHER_ROUND_BLOCK_SIZE) {
            size_t bj_end = (bj + FEISTEL_CIPHER_ROUND_BLOCK_SIZE < n) ? (bj + FEISTEL_CIPHER_ROUND_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
