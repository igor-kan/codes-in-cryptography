#include "interface.h"
#include <math.h>
#include <string.h>

uint8_t gf256_mul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; ++i) {
        if (b & 1u) p ^= a;
        uint8_t hi = a & 0x80u;
        a <<= 1;
        if (hi) a ^= 0x1Bu;
        b >>= 1;
    }
    return p;
}

uint8_t gf256_inv(uint8_t a) {
    if (a == 0) return 0;
    uint8_t res = 1;
    uint8_t base = a;
    uint8_t exp = 254;
    for (int i = 0; i < 8; ++i) {
        if (exp & 1u) res = gf256_mul(res, base);
        base = gf256_mul(base, base);
        exp >>= 1;
    }
    return res;
}
