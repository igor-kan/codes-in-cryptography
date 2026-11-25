#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    fe25519_d60_t a, b;
    fe25519_zero_d60(&a, 987654321ULL);
    fe25519_zero_d60(&b, 123456789ULL);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        fe25519_mul_d60(&a, &a, &b);
    sink = sink + (int64_t)a.limb[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("fe25519_arith_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
