#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    const uint8_t key[32] = {7}; uint8_t msg[256] = {9}, out[32];
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < 500; ++i) hmac_sha256_prf_mac(key, 32, msg, 256, out);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 500.0;
    printf("hmac_sha256_prf 256B ns=%.1f\n", ns);
    return 0;
}
