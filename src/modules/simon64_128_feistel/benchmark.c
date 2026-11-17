#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint32_t k[4]={1,2,3,4}; simon64_key_t ks; simon64_key_init(&ks,k); uint32_t b[2]={1,2}, o[2];
    timespec_get(&t0, TIME_UTC);
    volatile uint64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        simon64_encrypt_block(&ks, b, o); b[0]=o[0]; sink += o[1];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("simon64_128_feistel us=%.1f sink=%llu\n", us, (unsigned long long)sink);
    return 0;
}
