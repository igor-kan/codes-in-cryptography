#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t xxh_rotl(uint64_t v, int n) { return (v << n) | (v >> (64 - n)); }
static uint64_t xxh_read64(const uint8_t* p) {
    return (uint64_t)p[0] | ((uint64_t)p[1] << 8) | ((uint64_t)p[2] << 16) | ((uint64_t)p[3] << 24)
        | ((uint64_t)p[4] << 32) | ((uint64_t)p[5] << 40) | ((uint64_t)p[6] << 48) | ((uint64_t)p[7] << 56);
}
static uint32_t xxh_read32(const uint8_t* p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint64_t xxh_round(uint64_t acc, uint64_t input) {
    acc += input * XXH_P2;
    acc = xxh_rotl(acc, 31);
    return acc * XXH_P1;
}
static uint64_t xxh_merge(uint64_t acc, uint64_t lane) {
    acc ^= xxh_round(0ULL, lane);
    return acc * XXH_P1 + XXH_P4;
}
uint64_t xxh64_d61(const uint8_t* data, size_t len, uint64_t seed) {
    uint64_t h;
    size_t i = 0;
    if (len >= 32U) {
        uint64_t v1 = seed + XXH_P1 + XXH_P2;
        uint64_t v2 = seed + XXH_P2;
        uint64_t v3 = seed;
        uint64_t v4 = seed - XXH_P1;
        while (i + 32U <= len) {
            v1 = xxh_round(v1, xxh_read64(data + i)); i += 8U;
            v2 = xxh_round(v2, xxh_read64(data + i)); i += 8U;
            v3 = xxh_round(v3, xxh_read64(data + i)); i += 8U;
            v4 = xxh_round(v4, xxh_read64(data + i)); i += 8U;
        }
        h = xxh_rotl(v1, 1) + xxh_rotl(v2, 7) + xxh_rotl(v3, 12) + xxh_rotl(v4, 18);
        h = xxh_merge(h, v1);
        h = xxh_merge(h, v2);
        h = xxh_merge(h, v3);
        h = xxh_merge(h, v4);
    } else {
        h = seed + XXH_P5;
    }
    h += (uint64_t)len;
    while (i + 8U <= len) {
        h ^= xxh_round(0ULL, xxh_read64(data + i));
        h = xxh_rotl(h, 27) * XXH_P1 + XXH_P4;
        i += 8U;
    }
    if (i + 4U <= len) {
        h ^= (uint64_t)xxh_read32(data + i) * XXH_P1;
        h = xxh_rotl(h, 23) * XXH_P2 + XXH_P3;
        i += 4U;
    }
    while (i < len) {
        h ^= (uint64_t)data[i] * XXH_P5;
        h = xxh_rotl(h, 11) * XXH_P1;
        i += 1U;
    }
    h ^= h >> 33;
    h *= XXH_P2;
    h ^= h >> 29;
    h *= XXH_P3;
    h ^= h >> 32;
    return h;
}
