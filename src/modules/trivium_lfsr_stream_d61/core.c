#include "interface.h"
#include <math.h>
#include <string.h>

static uint8_t trivium_clock(trivium_state_d61_t* st) {
    uint8_t* s = st->bits;
    uint8_t t1 = (uint8_t)(s[65] ^ s[92]);
    uint8_t t2 = (uint8_t)(s[161] ^ s[176]);
    uint8_t t3 = (uint8_t)(s[242] ^ s[287]);
    uint8_t z = (uint8_t)(t1 ^ t2 ^ t3);
    t1 = (uint8_t)(t1 ^ (s[90] & s[91]) ^ s[170]);
    t2 = (uint8_t)(t2 ^ (s[174] & s[175]) ^ s[263]);
    t3 = (uint8_t)(t3 ^ (s[285] & s[286]) ^ s[68]);
    for (int i = 92; i > 0; --i) s[i] = s[i - 1];
    s[0] = t3;
    for (int i = 176; i > 93; --i) s[i] = s[i - 1];
    s[93] = t1;
    for (int i = 287; i > 177; --i) s[i] = s[i - 1];
    s[177] = t2;
    return z;
}
void trivium_init_d61(trivium_state_d61_t* st, const uint8_t key[10], const uint8_t iv[10]) {
    memset(st->bits, 0, sizeof(st->bits));
    for (int i = 0; i < 80; ++i) {
        st->bits[i] = (uint8_t)((key[i / 8] >> (i % 8)) & 1U);
        st->bits[93 + i] = (uint8_t)((iv[i / 8] >> (i % 8)) & 1U);
    }
    st->bits[285] = 1U;
    st->bits[286] = 1U;
    st->bits[287] = 1U;
    for (int i = 0; i < 1152; ++i) (void)trivium_clock(st);
}
uint8_t trivium_bit_d61(trivium_state_d61_t* st) {
    return trivium_clock(st);
}
uint8_t trivium_byte_d61(trivium_state_d61_t* st) {
    uint8_t out = 0U;
    for (int b = 0; b < 8; ++b) out |= (uint8_t)(trivium_clock(st) << b);
    return out;
}
uint64_t trivium_word_d61(trivium_state_d61_t* st) {
    uint64_t out = 0ULL;
    for (int b = 0; b < 64; ++b) out |= ((uint64_t)trivium_clock(st)) << b;
    return out;
}
