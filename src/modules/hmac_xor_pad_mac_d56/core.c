#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t fold64_core(uint64_t iv, const uint8_t *blk, size_t n) {
    uint64_t h = iv;
    for (size_t i = 0; i < n; ++i) {
        h ^= (uint64_t)blk[i] + 0x9E3779B97F4A7C15ULL + (h << 6) + (h >> 2);
        h = (h * 0xBF58476D1CE4E5B9ULL) ^ (h >> 29);
    }
    return h;
}

uint64_t nested_hmac64(const uint8_t *key, size_t klen, const uint8_t *msg, size_t mlen) {
    uint8_t kbuf[64];
    for (size_t i = 0; i < 64; ++i) kbuf[i] = 0;
    size_t copy_len = klen > 64 ? 64 : klen;
    for (size_t i = 0; i < copy_len; ++i) kbuf[i] = key[i];
    uint8_t ipad[64], opad[64];
    for (size_t i = 0; i < 64; ++i) {
        ipad[i] = kbuf[i] ^ 0x36u;
        opad[i] = kbuf[i] ^ 0x5Cu;
    }
    uint64_t inner = fold64_core(0x123456789ABCDEF0ULL, ipad, 64);
    inner = fold64_core(inner, msg, mlen);
    uint8_t digest[8];
    for (int i = 0; i < 8; ++i) digest[i] = (uint8_t)((inner >> (8 * i)) & 0xFFu);
    uint64_t outer = fold64_core(0xFEDCBA9876543210ULL, opad, 64);
    return fold64_core(outer, digest, 8);
}

int verify_hmac64(uint64_t a, uint64_t b) {
    uint64_t diff = a ^ b;
    return diff == 0 ? 1 : 0;
}
