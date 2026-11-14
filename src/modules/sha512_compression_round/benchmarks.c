/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round
 */

#include <stdint.h>

#define SHA512_COMPRESSION_ROUND_BENCH_ITERATIONS 100000

typedef struct sha512_compression_round_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} sha512_compression_round_bench_metrics_t;
