#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint64_t b_p = 2147483647ULL;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += dh_pow_mod(7ULL, (uint64_t)iter + 10ULL, b_p);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("ecdh_modp_dh_d58 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
