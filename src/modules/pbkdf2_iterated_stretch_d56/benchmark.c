#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint8_t b_p[4] = {1,2,3,4};
    const uint8_t b_s[4] = {5,6,7,8};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += stretch_kdf64(b_p, 4, b_s, 4, 8);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("pbkdf2_iterated_stretch_d56 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
