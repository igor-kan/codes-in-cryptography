#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    tea_key_t k={{1,2,3,4}}; uint8_t in[256]={0}, out[256];
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 150; ++iter) {
        tea_ctr_stream(&k, 99ULL, in, out, 256); sink += out[0];
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("tea_ctr_feistel ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 150.0, sink);
    return 0;
}
