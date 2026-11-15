#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    uint8_t k[32] = {1}, n[8] = {2}, buf[4096] = {0};
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < 200; ++i) salsa20_core_stream_xor(k, n, 0, buf, buf, 4096);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 200.0;
    printf("salsa20_core_stream 4KB ns=%.1f\n", ns);
    return 0;
}
