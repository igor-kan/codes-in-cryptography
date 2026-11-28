#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t key[10], iv[10];
    for (int i = 0; i < 10; ++i) { key[i] = (uint8_t)(i + 1); iv[i] = (uint8_t)(i * 3); }
    trivium_state_d61_t bst;
    trivium_init_d61(&bst, key, iv);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink = sink + (int64_t)trivium_word_d61(&bst);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("trivium_lfsr_stream_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
