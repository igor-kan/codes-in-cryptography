/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing
 */

#include <stdint.h>

#define SHAMIR_GF256_SHARING_BENCH_ITERATIONS 100000

typedef struct shamir_gf256_sharing_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} shamir_gf256_sharing_bench_metrics_t;
