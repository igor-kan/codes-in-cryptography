#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    musig_nonce_t ns[1] = {{5, 7, 1024, 16384}};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (int64_t)musig_agg_pub_nonce(ns, 1, 3);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("schnorr_musig2_nonce_agg us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
