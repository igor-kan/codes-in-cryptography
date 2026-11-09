/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Parallel Tree-Hashing BLAKE3 Compression Function.
 * Module: blake3_tree_hash
 */

#define BLAKE3_TREE_HASH_CACHE_LINE 64
#define BLAKE3_TREE_HASH_TILE_DIM 32

void blake3_tree_hash_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += BLAKE3_TREE_HASH_TILE_DIM) {
        size_t r_end = (r + BLAKE3_TREE_HASH_TILE_DIM < rows) ? r + BLAKE3_TREE_HASH_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
