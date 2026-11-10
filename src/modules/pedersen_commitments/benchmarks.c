/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#include <stdint.h>

#define PEDERSEN_COMMITMENTS_BENCH_SAMPLES 100000

typedef struct pedersen_commitments_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} pedersen_commitments_bench_stats_t;
