/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

#include <stdint.h>

#define CURVE448_GOLDILOCKS_BENCH_SAMPLES 100000

typedef struct curve448_goldilocks_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} curve448_goldilocks_bench_stats_t;
