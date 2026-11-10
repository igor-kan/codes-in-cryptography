/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#define PEDERSEN_COMMITMENTS_CACHE_LINE 64
#define PEDERSEN_COMMITMENTS_TILE_DIM 32

void pedersen_commitments_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += PEDERSEN_COMMITMENTS_TILE_DIM) {
        size_t r_end = (r + PEDERSEN_COMMITMENTS_TILE_DIM < rows) ? r + PEDERSEN_COMMITMENTS_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
