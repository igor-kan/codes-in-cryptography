#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    uint8_t state[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 16; ++j) state[j] = gf256_aes_rijndael_sbox_ct(state[j]);
        gf256_aes_rijndael_mix_state_fast(state);
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 10000.0;
    printf("gf256_aes_rijndael round_ns=%.1f\n", ns);
    return 0;
}
