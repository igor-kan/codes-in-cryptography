#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint64_t acc = 1ULL;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        acc = pedersen_commit_d60((uint64_t)iter, acc);
    sink = sink + (int64_t)acc;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("pedersen_commit_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
