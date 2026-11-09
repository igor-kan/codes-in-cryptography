/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Constant-Time Poly1305 One-Time Authentication MAC.
 * Module: poly1305_mac
 */

#define POLY1305_MAC_CACHE_LINE 64
#define POLY1305_MAC_TILE_DIM 32

void poly1305_mac_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += POLY1305_MAC_TILE_DIM) {
        size_t r_end = (r + POLY1305_MAC_TILE_DIM < rows) ? r + POLY1305_MAC_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
