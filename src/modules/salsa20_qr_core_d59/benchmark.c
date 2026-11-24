#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t bin[16], bout[16]; for (uint32_t i = 0; i < 16; ++i) bin[i] = i;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        salsa20_core(bin, bout); sink += bout[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("salsa20_qr_core_d59 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
