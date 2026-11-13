/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

#include <stdint.h>

#define SHA256_COMPRESSION_ROUND_BENCH_ITERATIONS 100000

typedef struct sha256_compression_round_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} sha256_compression_round_bench_metrics_t;
