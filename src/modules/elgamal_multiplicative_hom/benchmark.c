#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint64_t sk = 17ULL, pk = elg_pow(ELG_G, sk); elg_cipher_t c = elg_encrypt(pk, 12ULL, 5ULL);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (int64_t)elg_decrypt(sk, c);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("elgamal_multiplicative_hom us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
