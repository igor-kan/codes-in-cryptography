/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr
 */

#define CHACHA20_BLOCK_QR_LINE_SZ 64
#define CHACHA20_BLOCK_QR_TILE_SZ 32

void chacha20_block_qr_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += CHACHA20_BLOCK_QR_TILE_SZ) {
        size_t r_max = (r + CHACHA20_BLOCK_QR_TILE_SZ < rows) ? (r + CHACHA20_BLOCK_QR_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
