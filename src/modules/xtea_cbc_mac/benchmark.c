#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    xtea_key_t key = {{1, 2, 3, 4}};
    uint32_t v[2] = {0xDEADBEEFU, 0xCAFEBABEU};
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < 10000; ++i) xtea_cbc_mac_encrypt_block(&key, v);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 10000.0;
    printf("xtea_cbc_mac block_ns=%.2f\n", ns);
    return 0;
}
