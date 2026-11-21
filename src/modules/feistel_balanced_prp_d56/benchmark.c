#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t b_rk[4] = {3u, 5u, 7u, 11u};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += feistel4_enc((uint64_t)iter + 10ULL, b_rk);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("feistel_balanced_prp_d56 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
