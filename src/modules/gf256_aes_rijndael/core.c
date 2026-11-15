#include "interface.h"

uint8_t gf256_aes_rijndael_mul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; ++i) {
        uint8_t mask = (uint8_t)(-(b & 1U));
        p ^= (uint8_t)(a & mask);
        uint8_t hi = (uint8_t)(a >> 7);
        a = (uint8_t)((a << 1) ^ (uint8_t)((-(hi)) & AES_POLY));
        b >>= 1;
    }
    return p;
}

uint8_t gf256_aes_rijndael_inv(uint8_t a) {
    // a^254 by repeated squaring & mul in constant time
    uint8_t a2 = gf256_aes_rijndael_mul(a, a);
    uint8_t a3 = gf256_aes_rijndael_mul(a2, a);
    uint8_t a6 = gf256_aes_rijndael_mul(a3, a3);
    uint8_t a12 = gf256_aes_rijndael_mul(a6, a6);
    uint8_t a15 = gf256_aes_rijndael_mul(a12, a3);
    uint8_t a30 = gf256_aes_rijndael_mul(a15, a15);
    uint8_t a60 = gf256_aes_rijndael_mul(a30, a30);
    uint8_t a120 = gf256_aes_rijndael_mul(a60, a60);
    uint8_t a240 = gf256_aes_rijndael_mul(a120, a120);
    uint8_t a252 = gf256_aes_rijndael_mul(a240, a12);
    return gf256_aes_rijndael_mul(a252, a2);
}

static inline uint8_t rotl8(uint8_t x, int s) { return (uint8_t)((x << s) | (x >> (8 - s))); }

uint8_t gf256_aes_rijndael_sbox_ct(uint8_t x) {
    uint8_t inv = gf256_aes_rijndael_inv(x);
    return (uint8_t)(inv ^ rotl8(inv, 1) ^ rotl8(inv, 2) ^ rotl8(inv, 3) ^ rotl8(inv, 4) ^ 0x63U);
}

uint8_t gf256_aes_rijndael_invsbox_ct(uint8_t s) {
    uint8_t b = (uint8_t)(rotl8(s, 1) ^ rotl8(s, 3) ^ rotl8(s, 6) ^ 0x05U);
    return gf256_aes_rijndael_inv(b);
}

void gf256_aes_rijndael_mix_column(uint8_t c[4]) {
    uint8_t a0 = c[0], a1 = c[1], a2 = c[2], a3 = c[3];
    c[0] = gf256_aes_rijndael_mul(a0, 2) ^ gf256_aes_rijndael_mul(a1, 3) ^ a2 ^ a3;
    c[1] = a0 ^ gf256_aes_rijndael_mul(a1, 2) ^ gf256_aes_rijndael_mul(a2, 3) ^ a3;
    c[2] = a0 ^ a1 ^ gf256_aes_rijndael_mul(a2, 2) ^ gf256_aes_rijndael_mul(a3, 3);
    c[3] = gf256_aes_rijndael_mul(a0, 3) ^ a1 ^ a2 ^ gf256_aes_rijndael_mul(a3, 2);
}

void gf256_aes_rijndael_invmix_column(uint8_t c[4]) {
    uint8_t a0 = c[0], a1 = c[1], a2 = c[2], a3 = c[3];
    c[0] = gf256_aes_rijndael_mul(a0, 14) ^ gf256_aes_rijndael_mul(a1, 11) ^ gf256_aes_rijndael_mul(a2, 13) ^ gf256_aes_rijndael_mul(a3, 9);
    c[1] = gf256_aes_rijndael_mul(a0, 9) ^ gf256_aes_rijndael_mul(a1, 14) ^ gf256_aes_rijndael_mul(a2, 11) ^ gf256_aes_rijndael_mul(a3, 13);
    c[2] = gf256_aes_rijndael_mul(a0, 13) ^ gf256_aes_rijndael_mul(a1, 9) ^ gf256_aes_rijndael_mul(a2, 14) ^ gf256_aes_rijndael_mul(a3, 11);
    c[3] = gf256_aes_rijndael_mul(a0, 11) ^ gf256_aes_rijndael_mul(a1, 13) ^ gf256_aes_rijndael_mul(a2, 9) ^ gf256_aes_rijndael_mul(a3, 14);
}
