#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t b_k[4] = {1u,2u,3u,4u}, b_rk[44], b_v[2] = {9u,8u};
    simon64_expand(b_k, b_rk);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        simon64_enc(b_v, b_rk); sink += b_v[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("simon64_128_bit_d57 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
