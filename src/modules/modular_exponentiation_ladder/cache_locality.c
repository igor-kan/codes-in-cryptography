/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder
 */

#define MODULAR_EXPONENTIATION_LADDER_LINE_SZ 64
#define MODULAR_EXPONENTIATION_LADDER_TILE_SZ 32

void modular_exponentiation_ladder_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += MODULAR_EXPONENTIATION_LADDER_TILE_SZ) {
        size_t r_max = (r + MODULAR_EXPONENTIATION_LADDER_TILE_SZ < rows) ? (r + MODULAR_EXPONENTIATION_LADDER_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
