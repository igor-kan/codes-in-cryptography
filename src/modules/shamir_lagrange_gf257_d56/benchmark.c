#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    gf257_share_t b_sub[3] = {{1, 42}, {2, 91}, {3, 174}};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (uint64_t)gf257_reconstruct_secret(b_sub, 3);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("shamir_lagrange_gf257_d56 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
