#include "interface.h"
#include <math.h>
#include <string.h>

void rc4_drop_init(rc4_state_t* st, const uint8_t* key, size_t klen, size_t drop) {
    for (int k = 0; k < 256; ++k) st->S[k] = (uint8_t)k;
    uint8_t j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (uint8_t)(j + st->S[i] + key[i % klen]);
        uint8_t t = st->S[i]; st->S[i] = st->S[j]; st->S[j] = t;
    }
    st->i = 0; st->j = 0;
    for (size_t d = 0; d < drop; ++d) {
        st->i = (uint8_t)(st->i + 1U);
        st->j = (uint8_t)(st->j + st->S[st->i]);
        uint8_t t = st->S[st->i]; st->S[st->i] = st->S[st->j]; st->S[st->j] = t;
    }
}
void rc4_xor(rc4_state_t* st, uint8_t* buf, size_t len) {
    for (size_t k = 0; k < len; ++k) {
        st->i = (uint8_t)(st->i + 1U);
        st->j = (uint8_t)(st->j + st->S[st->i]);
        uint8_t t = st->S[st->i]; st->S[st->i] = st->S[st->j]; st->S[st->j] = t;
        uint8_t ks = st->S[(uint8_t)(st->S[st->i] + st->S[st->j])];
        buf[k] ^= ks;
    }
}
