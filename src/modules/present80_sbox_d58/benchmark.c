#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint64_t b_st = 0xFEDCBA9876543210ULL;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        b_st = spn_permute64(spn_apply_sbox(b_st)); sink += b_st;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("present80_sbox_d58 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
