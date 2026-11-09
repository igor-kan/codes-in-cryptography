/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Prime-Order Group Abstraction over Curve25519.
 * Module: ristretto255_group
 */

#define RISTRETTO255_GROUP_CACHE_LINE 64
#define RISTRETTO255_GROUP_TILE_DIM 32

void ristretto255_group_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += RISTRETTO255_GROUP_TILE_DIM) {
        size_t r_end = (r + RISTRETTO255_GROUP_TILE_DIM < rows) ? r + RISTRETTO255_GROUP_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
