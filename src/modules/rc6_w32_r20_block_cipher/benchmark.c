#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    rc6_ctx_t ctx; uint32_t k[4]={1,2,3,4}, b[4]={1,2,3,4}; rc6_key_setup(&ctx, k);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        rc6_encrypt_block(&ctx, b, b); sink += b[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("rc6_w32_r20_block_cipher us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
