#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t b_acc = 1u;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        b_acc = gf256_mul(b_acc, (uint8_t)(iter | 1)); sink += b_acc;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("gf256_aes_mul_inv_d56 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
