/**
 * Microbenchmark harness and cycle latency profiling for Append-Only Cryptographic Merkle Mountain Range.
 * Module: merkle_mountain_range
 */

#ifndef BENCH_MERKLE_MOUNTAIN_RANGE_H
#define BENCH_MERKLE_MOUNTAIN_RANGE_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct merkle_mountain_range_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} merkle_mountain_range_bench_metrics_t;

#endif /* BENCH_MERKLE_MOUNTAIN_RANGE_H */
