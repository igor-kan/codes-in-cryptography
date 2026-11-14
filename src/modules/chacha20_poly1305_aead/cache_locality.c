/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead
 */

#define CHACHA20_POLY1305_AEAD_LINE_SZ 64
#define CHACHA20_POLY1305_AEAD_TILE_SZ 32

void chacha20_poly1305_aead_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += CHACHA20_POLY1305_AEAD_TILE_SZ) {
        size_t r_max = (r + CHACHA20_POLY1305_AEAD_TILE_SZ < rows) ? (r + CHACHA20_POLY1305_AEAD_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
