#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t key[16];
    for (int i = 0; i < 16; ++i) key[i] = (uint8_t)(i + 1);
    rc5_ctx_d61_t bctx;
    rc5_setup_d61(&bctx, key);
    uint32_t bblk[2] = {0x11111111U, 0x22222222U}, bout[2];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        bblk[0] ^= (uint32_t)iter;
    rc5_encrypt_d61(&bctx, bblk, bout);
    sink = sink + (int64_t)bout[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("rc5_32_12_16_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
