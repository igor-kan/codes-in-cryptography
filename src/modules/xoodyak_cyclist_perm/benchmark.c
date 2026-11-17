#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    xoodoo_state_t s={0}; s.lanes[0]=1;
    timespec_get(&t0, TIME_UTC);
    volatile uint64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        xoodoo_permute_12(&s); sink += s.lanes[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("xoodyak_cyclist_perm us=%.1f sink=%llu\n", us, (unsigned long long)sink);
    return 0;
}
