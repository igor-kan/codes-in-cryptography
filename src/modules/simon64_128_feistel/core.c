#include "interface.h"

static uint32_t ror32(uint32_t x, int r) { return (x >> r) | (x << (32 - r)); }
static uint32_t rol32(uint32_t x, int r) { return (x << r) | (x >> (32 - r)); }

static const uint64_t SIMON_Z3 = 0x99DF8049B8B83882ULL;

void simon64_key_init(simon64_key_t* ks, const uint32_t key_words[4]) {
    for (int i = 0; i < 4; ++i) ks->rk[i] = key_words[i];
    for (int i = 4; i < 44; ++i) {
        uint32_t tmp = ror32(ks->rk[i - 1], 3) ^ ks->rk[i - 3];
        tmp ^= ror32(tmp, 1);
        uint32_t zbit = (uint32_t)((SIMON_Z3 >> ((i - 4) % 62)) & 1ULL);
        ks->rk[i] = ~ks->rk[i - 4] ^ tmp ^ zbit ^ 3U;
    }
}

void simon64_encrypt_block(const simon64_key_t* ks, const uint32_t pt[2], uint32_t ct[2]) {
    uint32_t x = pt[1], y = pt[0];
    for (int r = 0; r < 44; ++r) {
        uint32_t f = (rol32(x, 1) & rol32(x, 8)) ^ rol32(x, 2);
        uint32_t nx = y ^ f ^ ks->rk[r];
        y = x;
        x = nx;
    }
    ct[0] = y;
    ct[1] = x;
}

void simon64_decrypt_block(const simon64_key_t* ks, const uint32_t ct[2], uint32_t pt[2]) {
    uint32_t x = ct[1], y = ct[0];
    for (int r = 43; r >= 0; --r) {
        uint32_t ny = x;
        uint32_t nx_prev = y;
        uint32_t f = (rol32(nx_prev, 1) & rol32(nx_prev, 8)) ^ rol32(nx_prev, 2);
        uint32_t old_y = ny ^ f ^ ks->rk[r];
        x = nx_prev;
        y = old_y;
    }
    pt[0] = y;
    pt[1] = x;
}
