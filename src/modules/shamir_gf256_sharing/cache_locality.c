/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing
 */

#define SHAMIR_GF256_SHARING_LINE_SZ 64
#define SHAMIR_GF256_SHARING_TILE_SZ 32

void shamir_gf256_sharing_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += SHAMIR_GF256_SHARING_TILE_SZ) {
        size_t r_max = (r + SHAMIR_GF256_SHARING_TILE_SZ < rows) ? (r + SHAMIR_GF256_SHARING_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
