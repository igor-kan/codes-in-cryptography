#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t rotl64(uint64_t x, int b) { return (x << b) | (x >> (64 - b)); }
static void sipround(uint64_t* v0, uint64_t* v1, uint64_t* v2, uint64_t* v3) {
    *v0 += *v1; *v1 = rotl64(*v1, 13); *v1 ^= *v0; *v0 = rotl64(*v0, 32);
    *v2 += *v3; *v3 = rotl64(*v3, 16); *v3 ^= *v2;
    *v0 += *v3; *v3 = rotl64(*v3, 21); *v3 ^= *v0;
    *v2 += *v1; *v1 = rotl64(*v1, 17); *v1 ^= *v2; *v2 = rotl64(*v2, 32);
}
uint64_t siphash24_d60(uint64_t k0, uint64_t k1, const uint8_t* in, size_t len) {
    uint64_t v0 = 0x736f6d6570736575ULL ^ k0;
    uint64_t v1 = 0x646f72616e646f6dULL ^ k1;
    uint64_t v2 = 0x6c7967656e657261ULL ^ k0;
    uint64_t v3 = 0x7465646279746573ULL ^ k1;
    size_t blocks = len / 8U;
    for (size_t i = 0; i < blocks; ++i) {
        const uint8_t* p = in + i * 8U;
        uint64_t m = 0;
        for (int b = 0; b < 8; ++b) m |= ((uint64_t)p[b]) << (8 * b);
        v3 ^= m;
        sipround(&v0, &v1, &v2, &v3); sipround(&v0, &v1, &v2, &v3);
        v0 ^= m;
    }
    uint64_t last = ((uint64_t)len & 0xffULL) << 56;
    size_t rem = len & 7U;
    for (size_t b = 0; b < rem; ++b) last |= ((uint64_t)in[blocks * 8U + b]) << (8 * b);
    v3 ^= last;
    sipround(&v0, &v1, &v2, &v3); sipround(&v0, &v1, &v2, &v3);
    v0 ^= last;
    v2 ^= 0xffULL;
    for (int r = 0; r < 4; ++r) sipround(&v0, &v1, &v2, &v3);
    return v0 ^ v1 ^ v2 ^ v3;
}
