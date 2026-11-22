#include "interface.h"
#include <math.h>
#include <string.h>

void rc4_drop_xor(const uint8_t *key, size_t klen, size_t drop_n, uint8_t *buf, size_t len) {
    uint8_t s[256];
    for (int i = 0; i < 256; ++i) s[i] = (uint8_t)i;
    uint8_t j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (uint8_t)(j + s[i] + key[(size_t)i % klen]);
        uint8_t tmp = s[i]; s[i] = s[j]; s[j] = tmp;
    }
    uint8_t a = 0, b = 0;
    for (size_t k = 0; k < drop_n; ++k) {
        a = (uint8_t)(a + 1u);
        b = (uint8_t)(b + s[a]);
        uint8_t tmp = s[a]; s[a] = s[b]; s[b] = tmp;
    }
    for (size_t k = 0; k < len; ++k) {
        a = (uint8_t)(a + 1u);
        b = (uint8_t)(b + s[a]);
        uint8_t tmp = s[a]; s[a] = s[b]; s[b] = tmp;
        buf[k] ^= s[(uint8_t)(s[a] + s[b])];
    }
}
