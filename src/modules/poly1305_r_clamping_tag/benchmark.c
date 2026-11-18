#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t raw[32] = {1,2,3}; poly1305_key_t pk; poly1305_clamp_key(raw, &pk); uint64_t b[2]={1,2};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (int64_t)poly1305_short_tag64(&pk, b, 2);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("poly1305_r_clamping_tag us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
