#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t prf_mix(uint64_t st, const uint8_t *data, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        st ^= (uint64_t)data[i];
        st *= 0x9E3779B97F4A7C15ULL;
        st ^= st >> 27;
    }
    return st;
}

uint64_t stretch_kdf64(const uint8_t *pass, size_t plen, const uint8_t *salt, size_t slen, uint32_t rounds) {
    if (rounds == 0) return 0;
    uint64_t u = prf_mix(0xCBF29CE484222325ULL, pass, plen);
    u = prf_mix(u, salt, slen);
    uint64_t acc = u;
    for (uint32_t r = 1; r < rounds; ++r) {
        uint8_t blk[8];
        for (int b = 0; b < 8; ++b) blk[b] = (uint8_t)((u >> (8 * b)) & 0xFFu);
        u = prf_mix(0x94D049BB133111EBULL, blk, 8);
        u = prf_mix(u, pass, plen);
        acc ^= u;
    }
    return acc;
}
