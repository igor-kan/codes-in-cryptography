#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    rabin_key_t rk = {103ULL, 107ULL, 11021ULL}; uint64_t r[4];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        rabin_decrypt_roots(&rk, 144ULL, r); sink += (int64_t)r[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("rabin_williams_sqrt_trap us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
