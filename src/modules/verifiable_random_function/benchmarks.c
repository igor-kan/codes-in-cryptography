/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#include <stdint.h>

#define VERIFIABLE_RANDOM_FUNCTION_BENCH_SAMPLES 100000

typedef struct verifiable_random_function_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} verifiable_random_function_bench_stats_t;
