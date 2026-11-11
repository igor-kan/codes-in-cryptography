/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#define MERKLE_SUM_TREE_CACHE_LINE 64
#define MERKLE_SUM_TREE_TILE_DIM 32

void merkle_sum_tree_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += MERKLE_SUM_TREE_TILE_DIM) {
        size_t r_end = (r + MERKLE_SUM_TREE_TILE_DIM < rows) ? r + MERKLE_SUM_TREE_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
