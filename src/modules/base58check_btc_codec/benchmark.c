#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    const uint8_t p[21]={0,1,2,3,4}; char out[64]; size_t ol=0;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 150; ++iter) {
        b58check_encode(p, 21, out, sizeof(out), &ol); sink += ol;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("base58check_btc_codec ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 150.0, sink);
    return 0;
}
