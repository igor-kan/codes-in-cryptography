/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Falcon Lattice Fast Fourier Orthogonalization (LDL).
 * Module: falcon_fldl
 */

#define FALCON_FLDL_CACHE_LINE 64
#define FALCON_FLDL_TILE_DIM 32

void falcon_fldl_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += FALCON_FLDL_TILE_DIM) {
        size_t r_end = (r + FALCON_FLDL_TILE_DIM < rows) ? r + FALCON_FLDL_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
