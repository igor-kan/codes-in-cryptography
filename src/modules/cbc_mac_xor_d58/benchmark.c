#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint64_t b_m[3] = {1ULL, 2ULL, 3ULL};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += cbc_mac64((uint64_t)iter + 1ULL, b_m, 3);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("cbc_mac_xor_d58 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
