#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t bbuf[64];
    for (uint32_t i = 0; i < 64U; ++i) bbuf[i] = (uint8_t)(i * 7U + 1U);
    uint8_t bdig[16];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        md5_digest_d61(bbuf, 64U, bdig);
    sink = sink + (int64_t)bdig[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("md5_stream_digest_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
