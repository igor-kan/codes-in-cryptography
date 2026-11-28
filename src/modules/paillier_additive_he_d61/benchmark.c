#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint64_t bacc = 0ULL;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        bacc = paillier_encrypt_d61((uint64_t)(iter % 1000), 11ULL);
    sink = sink + (int64_t)paillier_decrypt_d61(bacc);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("paillier_additive_he_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
