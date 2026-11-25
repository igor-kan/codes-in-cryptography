#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t key[32], blk[16], mac[16];
    for (int i=0;i<32;++i) key[i]=(uint8_t)i;
    for (int i=0;i<16;++i) blk[i]=(uint8_t)(i*3);
    poly1305_state_t st;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        poly1305_init_d60(&st, key);
    poly1305_block_d60(&st, blk);
    poly1305_finish_d60(&st, mac);
    sink = sink + (int64_t)mac[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("poly1305_mac_step_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
