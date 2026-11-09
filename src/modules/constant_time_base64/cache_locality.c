/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Side-Channel Immune Constant-Time Base64 Engine.
 * Module: constant_time_base64
 */

#define CONSTANT_TIME_BASE64_CACHE_LINE 64
#define CONSTANT_TIME_BASE64_TILE_DIM 32

void constant_time_base64_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += CONSTANT_TIME_BASE64_TILE_DIM) {
        size_t r_end = (r + CONSTANT_TIME_BASE64_TILE_DIM < rows) ? r + CONSTANT_TIME_BASE64_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
