/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block
 */

#define GCM_GHASH_BLOCK_LINE_SZ 64
#define GCM_GHASH_BLOCK_TILE_SZ 32

void gcm_ghash_block_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += GCM_GHASH_BLOCK_TILE_SZ) {
        size_t r_max = (r + GCM_GHASH_BLOCK_TILE_SZ < rows) ? (r + GCM_GHASH_BLOCK_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
