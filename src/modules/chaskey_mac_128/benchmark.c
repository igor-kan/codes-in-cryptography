#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    uint8_t k[16]={1}, m[128]={2}, t[16]; chaskey_ctx_t c; chaskey_init(&c, k);
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 150; ++iter) {
        chaskey_mac(&c, m, 128, t); m[0]^=t[0]; sink+=t[0];
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("chaskey_mac_128 ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 150.0, sink);
    return 0;
}
