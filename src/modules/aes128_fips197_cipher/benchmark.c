#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    uint8_t k[16]={0}, p[16]={1}, c[16]; aes128_ctx_t ctx; aes128_init(&ctx, k);
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 150; ++iter) {
        aes128_encrypt_block(&ctx, p, c); p[0]=c[0]; sink += c[0];
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("aes128_fips197_cipher ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 150.0, sink);
    return 0;
}
