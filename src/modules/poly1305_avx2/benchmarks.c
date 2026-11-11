/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for AVX2-Accelerated Poly1305 Message Authentication Code.
 * Module: poly1305_avx2
 */

#include <stdint.h>

#define POLY1305_AVX2_BENCH_SAMPLES 100000

typedef struct poly1305_avx2_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} poly1305_avx2_bench_stats_t;
