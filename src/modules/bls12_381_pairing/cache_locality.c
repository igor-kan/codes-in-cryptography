/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#define BLS12_381_PAIRING_CACHE_LINE 64
#define BLS12_381_PAIRING_TILE_DIM 32

void bls12_381_pairing_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += BLS12_381_PAIRING_TILE_DIM) {
        size_t r_end = (r + BLS12_381_PAIRING_TILE_DIM < rows) ? r + BLS12_381_PAIRING_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
