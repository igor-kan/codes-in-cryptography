/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#include <stdint.h>

#define VERIFIABLE_SECRET_SHARING_BENCH_ITERATIONS 100000

typedef struct verifiable_secret_sharing_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} verifiable_secret_sharing_bench_result_t;
