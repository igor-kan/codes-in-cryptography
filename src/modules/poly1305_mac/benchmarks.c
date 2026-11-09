/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Constant-Time Poly1305 One-Time Authentication MAC.
 * Module: poly1305_mac
 */

#include <stdint.h>

#define POLY1305_MAC_BENCH_SAMPLES 100000

typedef struct poly1305_mac_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} poly1305_mac_bench_stats_t;
