/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#define VERIFIABLE_RANDOM_FUNCTION_CACHE_LINE 64
#define VERIFIABLE_RANDOM_FUNCTION_TILE_DIM 32

void verifiable_random_function_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += VERIFIABLE_RANDOM_FUNCTION_TILE_DIM) {
        size_t r_end = (r + VERIFIABLE_RANDOM_FUNCTION_TILE_DIM < rows) ? r + VERIFIABLE_RANDOM_FUNCTION_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
