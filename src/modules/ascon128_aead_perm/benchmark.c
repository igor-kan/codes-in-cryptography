#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    const uint8_t key[16] = {1}; const uint8_t nonce[16] = {2};
    uint8_t pt[1024] = {0}, ct[1024] = {0}, tag[16];
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int it = 0; it < 200; ++it) ascon128_aead_perm_encrypt(key, nonce, NULL, 0, pt, 1024, ct, tag);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 200.0;
    printf("ascon128_aead_perm 1KB ns=%.1f\n", ns);
    return 0;
}
