#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t b_k[4] = {5u,6u,7u,8u}, b_v[2] = {1u,2u};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        tea_encrypt(b_v, b_k); sink += b_v[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("tea_classic_64_d58 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
