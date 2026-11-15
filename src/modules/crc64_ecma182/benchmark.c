#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    crc64_table_t tbl; crc64_ecma182_init_table(&tbl);
    uint8_t buf[4096] = {1}; volatile uint64_t c = 0;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < 500; ++i) c ^= crc64_ecma182_table_eval(&tbl, 0, buf, 4096);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 500.0;
    printf("crc64_ecma182 4KB ns=%.1f sink=%llu\n", ns, (unsigned long long)c);
    return 0;
}
