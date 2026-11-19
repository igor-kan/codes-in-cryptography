#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    hyperplane_share_t a=blak_deal_share(42,9,1,2), b=blak_deal_share(42,9,3,4);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (int64_t)blak_recover_secret(a, b);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("blakley_hyperplane_share us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
