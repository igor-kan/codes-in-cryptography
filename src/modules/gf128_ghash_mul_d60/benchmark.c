#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    gf128_elem_t h = {0x66e94bd4ef8a2c3bULL, 0x884cfa59ca342b2eULL};
    gf128_elem_t a = {0x0388dace60b6a392ULL, 0xf328c2b971b2fe78ULL};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        a = gf128_mul_d60(a, h);
    sink = sink + (int64_t)(a.hi ^ a.lo);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("gf128_ghash_mul_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
