#include "interface.h"

static uint32_t rotl(uint32_t x, int n) { return (x << n) | (x >> (32 - n)); }

void hchacha20_fast_qr(uint32_t s[16], int a, int b, int c, int d) {
    s[a] += s[b]; s[d] = rotl(s[d] ^ s[a], 16);
    s[c] += s[d]; s[b] = rotl(s[b] ^ s[c], 12);
    s[a] += s[b]; s[d] = rotl(s[d] ^ s[a], 8);
    s[c] += s[d]; s[b] = rotl(s[b] ^ s[c], 7);
}
