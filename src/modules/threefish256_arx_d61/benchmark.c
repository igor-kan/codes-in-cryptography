#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint64_t bk[4] = {1ULL, 2ULL, 3ULL, 4ULL}, btw[2] = {5ULL, 6ULL};
    uint64_t bx[4] = {7ULL, 8ULL, 9ULL, 10ULL}, bo[4];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        threefish256_encrypt_d61(bk, btw, bx, bo);
    bx[0] ^= (uint64_t)iter;
    sink = sink + (int64_t)bo[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("threefish256_arx_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
