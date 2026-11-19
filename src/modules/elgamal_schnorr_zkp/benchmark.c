#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint64_t sk=555ULL, pk=zkp_pow_p(ZKP_G, sk); schnorr_zkp_t pf=schnorr_prove(sk, 777ULL, 1ULL);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += schnorr_verify(pk, 1ULL, pf) ? 1 : 0;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("elgamal_schnorr_zkp us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
