#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    mh_key_d61_t bk;
    mh_public_key_d61(&bk);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink = sink + (int64_t)mh_decrypt_d61(&bk, mh_encrypt_d61(&bk, (uint8_t)(iter & 0xff)));
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("merkle_hellman_knapsack_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
