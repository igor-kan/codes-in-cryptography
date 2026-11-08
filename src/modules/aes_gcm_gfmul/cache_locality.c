/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#define AES_GCM_GFMUL_CACHE_LINE_SIZE 64
#define AES_GCM_GFMUL_L1_TILE_SIZE 32

void aes_gcm_gfmul_cache_tiled_transform(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += AES_GCM_GFMUL_L1_TILE_SIZE) {
        size_t r_end = (r + AES_GCM_GFMUL_L1_TILE_SIZE < rows) ? r + AES_GCM_GFMUL_L1_TILE_SIZE : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.0001;
            }
        }
    }
}
