#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t g_rotl(uint32_t x, int bits) { return (x << bits) | (x >> (32 - bits)); }
void gimli_permute(gimli_state_t* st) {
    uint32_t* s = st->s;
    for (int round = 24; round > 0; --round) {
        for (int col = 0; col < 4; ++col) {
            uint32_t x = g_rotl(s[col], 24);
            uint32_t y = g_rotl(s[4 + col], 9);
            uint32_t z = s[8 + col];
            s[8 + col] = x ^ (z << 1) ^ ((y & z) << 2);
            s[4 + col] = y ^ x        ^ ((x | z) << 1);
            s[col]     = z ^ y        ^ ((x & y) << 3);
        }
        if ((round & 3) == 0) {
            uint32_t t = s[0]; s[0] = s[1]; s[1] = t;
            t = s[2]; s[2] = s[3]; s[3] = t;
            s[0] ^= (0x9e377900U | (uint32_t)round);
        }
        if ((round & 3) == 2) {
            uint32_t t = s[0]; s[0] = s[2]; s[2] = t;
            t = s[1]; s[1] = s[3]; s[3] = t;
        }
    }
}
