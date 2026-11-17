#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    kek128_t k={1,2}; uint64_t pt[4]={1,2,3,4}, ct[5];
    timespec_get(&t0, TIME_UTC);
    volatile uint64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        rfc3394_wrap(k, pt, 4, ct); sink += ct[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("rfc3394_keywrap_cipher us=%.1f sink=%llu\n", us, (unsigned long long)sink);
    return 0;
}
