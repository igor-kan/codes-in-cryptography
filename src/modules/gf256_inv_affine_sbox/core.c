#include "interface.h"
#include <math.h>
#include <string.h>

uint8_t gf256_mul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; ++i) {
        if (b & 1U) p ^= a;
        bool hi = (a & 0x80U) != 0;
        a <<= 1;
        if (hi) a ^= 0x1bU;
        b >>= 1;
    }
    return p;
}
uint8_t gf256_inv(uint8_t a) {
    uint8_t r = 1, cur = a;
    for (int e = 1; e < 8; ++e) { cur = gf256_mul(cur, cur); r = gf256_mul(r, cur); }
    return r;
}
static uint8_t rotl8(uint8_t x, int n) { return (uint8_t)((x << n) | (x >> (8 - n))); }
uint8_t aes_sbox_eval(uint8_t x) {
    uint8_t inv = (x == 0) ? 0 : gf256_inv(x);
    return (uint8_t)(inv ^ rotl8(inv, 1) ^ rotl8(inv, 2) ^ rotl8(inv, 3) ^ rotl8(inv, 4) ^ 0x63U);
}
