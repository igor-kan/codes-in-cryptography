#include "interface.h"
#include <math.h>
#include <string.h>

static const int tf_rot[8][2] = {
    {14, 16}, {52, 57}, {23, 40}, {5, 37}, {25, 33}, {46, 12}, {58, 22}, {32, 32}
};
static uint64_t tf_rotl64(uint64_t v, int n) { return (v << n) | (v >> (64 - n)); }
static uint64_t tf_rotr64(uint64_t v, int n) { return (v >> n) | (v << (64 - n)); }
static void tf256_schedule(const uint64_t key[4], const uint64_t tweak[2], uint64_t ks[19][4]) {
    uint64_t k[5], t[3];
    for (int i = 0; i < 4; ++i) k[i] = key[i];
    k[4] = 0x1BD11BDAA9FC1A22ULL ^ key[0] ^ key[1] ^ key[2] ^ key[3];
    t[0] = tweak[0];
    t[1] = tweak[1];
    t[2] = tweak[0] ^ tweak[1];
    for (int s = 0; s < 19; ++s) {
        ks[s][0] = k[s % 5];
        ks[s][1] = k[(s + 1) % 5] + t[s % 3];
        ks[s][2] = k[(s + 2) % 5] + t[(s + 1) % 3];
        ks[s][3] = k[(s + 3) % 5] + (uint64_t)s;
    }
}
void threefish256_encrypt_d61(const uint64_t key[4], const uint64_t tweak[2], const uint64_t pt[4], uint64_t ct[4]) {
    uint64_t ks[19][4], x[4];
    tf256_schedule(key, tweak, ks);
    for (int i = 0; i < 4; ++i) x[i] = pt[i];
    for (int d = 0; d < TF256_ROUNDS; ++d) {
        if (d % 4 == 0) {
            for (int i = 0; i < 4; ++i) x[i] += ks[d / 4][i];
        }
        x[0] += x[1]; x[1] = tf_rotl64(x[1], tf_rot[d % 8][0]) ^ x[0];
        x[2] += x[3]; x[3] = tf_rotl64(x[3], tf_rot[d % 8][1]) ^ x[2];
        uint64_t tmp = x[1];
        x[1] = x[3];
        x[3] = tmp;
    }
    for (int i = 0; i < 4; ++i) x[i] += ks[18][i];
    for (int i = 0; i < 4; ++i) ct[i] = x[i];
}
void threefish256_decrypt_d61(const uint64_t key[4], const uint64_t tweak[2], const uint64_t ct[4], uint64_t pt[4]) {
    uint64_t ks[19][4], x[4];
    tf256_schedule(key, tweak, ks);
    for (int i = 0; i < 4; ++i) x[i] = ct[i] - ks[18][i];
    for (int d = TF256_ROUNDS - 1; d >= 0; --d) {
        uint64_t tmp = x[1];
        x[1] = x[3];
        x[3] = tmp;
        x[1] = tf_rotr64(x[1] ^ x[0], tf_rot[d % 8][0]); x[0] -= x[1];
        x[3] = tf_rotr64(x[3] ^ x[2], tf_rot[d % 8][1]); x[2] -= x[3];
        if (d % 4 == 0) {
            for (int i = 0; i < 4; ++i) x[i] -= ks[d / 4][i];
        }
    }
    for (int i = 0; i < 4; ++i) pt[i] = x[i];
}
