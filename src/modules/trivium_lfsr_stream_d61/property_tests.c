#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(trivium_lfsr_stream_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t key[10], iv1[10], iv2[10];
    for (int i = 0; i < 10; ++i) {
        key[i] = (uint8_t)(i * 7 + 1);
        iv1[i] = (uint8_t)i;
        iv2[i] = (uint8_t)(i + 1);
    }
    trivium_state_d61_t s1, s2, s3, s4;
    trivium_init_d61(&s1, key, iv1);
    trivium_init_d61(&s2, key, iv2);
    uint64_t diff = 0ULL;
    for (int i = 0; i < 8; ++i) diff |= trivium_word_d61(&s1) ^ trivium_word_d61(&s2);
    assert(diff != 0ULL);
    trivium_init_d61(&s3, key, iv1);
    trivium_init_d61(&s4, key, iv1);
    uint64_t ks = trivium_word_d61(&s3);
    uint64_t ks2 = trivium_word_d61(&s4);
    assert(ks == ks2);
    uint8_t msg[8], enc[8], dec[8];
    for (int i = 0; i < 8; ++i) msg[i] = (uint8_t)(i + 3);
    for (int i = 0; i < 8; ++i) {
        enc[i] = (uint8_t)(msg[i] ^ ((ks >> (8 * i)) & 0xffU));
        dec[i] = (uint8_t)(enc[i] ^ ((ks2 >> (8 * i)) & 0xffU));
    }
    assert(memcmp(msg, dec, 8) == 0);
    return 0;
}
