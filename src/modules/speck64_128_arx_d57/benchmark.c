#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t b_k[4] = {1u,2u,3u,4u}, b_rk[27], b_v[2] = {5u,6u};
    speck64_expand(b_k, b_rk);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        speck64_enc(b_v, b_rk); sink += b_v[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("speck64_128_arx_d57 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
