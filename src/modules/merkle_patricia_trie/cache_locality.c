/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#define MERKLE_PATRICIA_TRIE_CACHE_LINE 64
#define MERKLE_PATRICIA_TRIE_TILE_DIM 32

void merkle_patricia_trie_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += MERKLE_PATRICIA_TRIE_TILE_DIM) {
        size_t r_end = (r + MERKLE_PATRICIA_TRIE_TILE_DIM < rows) ? r + MERKLE_PATRICIA_TRIE_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
