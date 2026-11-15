#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    const uint8_t seed[32] = {1};
    chacha_drbg_t rng; chacha_drbg_csprng_seed(&rng, seed);
    uint8_t buf[1024];
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < 500; ++i) chacha_drbg_csprng_bytes(&rng, buf, 1024);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 500.0;
    printf("chacha_drbg_csprng 1KB ns=%.1f\n", ns);
    return 0;
}
