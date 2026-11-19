#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t key[4] = {1,2,3,4}, b[4] = {0}; rc4_state_t s; rc4_drop_init(&s, key, 4, 64);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        rc4_xor(&s, b, 4); sink += b[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("rc4_drop3072_stream_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
