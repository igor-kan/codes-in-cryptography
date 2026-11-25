#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint32_t k[8] = {1,2,3,4,5,6,7,8}, n[3] = {9,10,11};
    uint32_t out[16];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        chacha20_block_words_d60(k, (uint32_t)iter, n, out);
    sink = sink + (int64_t)(out[0] ^ out[15]);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("chacha20_quarter_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
