/**
 * Microbenchmark harness and cycle latency profiling for Constant-Time Montgomery Reduction and Ladder.
 * Module: montgomery_arithmetic
 */

#ifndef BENCH_MONTGOMERY_ARITHMETIC_H
#define BENCH_MONTGOMERY_ARITHMETIC_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct montgomery_arithmetic_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} montgomery_arithmetic_bench_metrics_t;

#endif /* BENCH_MONTGOMERY_ARITHMETIC_H */
