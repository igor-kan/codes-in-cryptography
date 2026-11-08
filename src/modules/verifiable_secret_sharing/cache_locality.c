/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#define VERIFIABLE_SECRET_SHARING_CACHE_LINE_SIZE 64
#define VERIFIABLE_SECRET_SHARING_L1_TILE_SIZE 32

void verifiable_secret_sharing_cache_tiled_transform(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += VERIFIABLE_SECRET_SHARING_L1_TILE_SIZE) {
        size_t r_end = (r + VERIFIABLE_SECRET_SHARING_L1_TILE_SIZE < rows) ? r + VERIFIABLE_SECRET_SHARING_L1_TILE_SIZE : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.0001;
            }
        }
    }
}
