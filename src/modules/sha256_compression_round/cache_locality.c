/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

#define SHA256_COMPRESSION_ROUND_LINE_SZ 64
#define SHA256_COMPRESSION_ROUND_TILE_SZ 32

void sha256_compression_round_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += SHA256_COMPRESSION_ROUND_TILE_SZ) {
        size_t r_max = (r + SHA256_COMPRESSION_ROUND_TILE_SZ < rows) ? (r + SHA256_COMPRESSION_ROUND_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
