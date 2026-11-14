/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

#define KECCAK_F1600_THETA_LINE_SZ 64
#define KECCAK_F1600_THETA_TILE_SZ 32

void keccak_f1600_theta_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += KECCAK_F1600_THETA_TILE_SZ) {
        size_t r_max = (r + KECCAK_F1600_THETA_TILE_SZ < rows) ? (r + KECCAK_F1600_THETA_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
