#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t brk[8] = {1u,2u,3u,4u,5u,6u,7u,8u};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += feistel8_enc((uint64_t)iter, brk);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("feistel_8round_d59 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
