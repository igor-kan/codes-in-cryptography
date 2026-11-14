/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block
 */

#include <stdint.h>

#define GCM_GHASH_BLOCK_BENCH_ITERATIONS 100000

typedef struct gcm_ghash_block_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} gcm_ghash_block_bench_metrics_t;
