#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t mix64_kdf(uint64_t st, const uint8_t *buf, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        st ^= (uint64_t)buf[i] + 0x9E3779B97F4A7C15ULL;
        st *= 0xBF58476D1CE4E5B9ULL;
        st ^= st >> 27;
    }
    return st;
}

uint64_t hkdf_extract64(const uint8_t *salt, size_t slen, const uint8_t *ikm, size_t ilen) {
    uint64_t s = mix64_kdf(0x243F6A8885A308D3ULL, salt, slen);
    return mix64_kdf(s, ikm, ilen);
}

uint64_t hkdf_expand64(uint64_t prk, const uint8_t *info, size_t infolen, uint8_t counter) {
    uint64_t st = mix64_kdf(prk ^ 0x13198A2E03707344ULL, info, infolen);
    uint8_t c = counter;
    return mix64_kdf(st, &c, 1);
}
