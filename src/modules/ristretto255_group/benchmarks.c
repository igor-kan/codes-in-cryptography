/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Prime-Order Group Abstraction over Curve25519.
 * Module: ristretto255_group
 */

#include <stdint.h>

#define RISTRETTO255_GROUP_BENCH_SAMPLES 100000

typedef struct ristretto255_group_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} ristretto255_group_bench_stats_t;
