#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t b_in[16];
    uint32_t b_out[16];
    for (uint32_t i = 0; i < 16; ++i) b_in[i] = i;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        chacha20_block_words(b_in, b_out); sink += b_out[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("chacha_quarter_round_d56 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
