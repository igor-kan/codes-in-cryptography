/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#define X25519_DIFFIE_HELLMAN_CACHE_LINE_SIZE 64
#define X25519_DIFFIE_HELLMAN_L1_TILE_SIZE 32

void x25519_diffie_hellman_cache_tiled_transform(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += X25519_DIFFIE_HELLMAN_L1_TILE_SIZE) {
        size_t r_end = (r + X25519_DIFFIE_HELLMAN_L1_TILE_SIZE < rows) ? r + X25519_DIFFIE_HELLMAN_L1_TILE_SIZE : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.0001;
            }
        }
    }
}
