#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    const uint64_t key[2] = {1, 2}; speck128_rk_t rk;
    speck128_ctr_cipher_expand(key, &rk);
    uint64_t pt[2] = {10, 20}, ct[2] = {0};
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < 20000; ++i) { speck128_ctr_cipher_enc_block(&rk, pt, ct); pt[0] = ct[0]; }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 20000.0;
    printf("speck128_ctr_cipher block_ns=%.2f\n", ns);
    return 0;
}
