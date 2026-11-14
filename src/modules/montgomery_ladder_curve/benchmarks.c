/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Montgomery Ladder Scalar Multiplication on Curves.
 * Module: montgomery_ladder_curve
 */

#include <stdint.h>

#define MONTGOMERY_LADDER_CURVE_BENCH_ITERATIONS 100000

typedef struct montgomery_ladder_curve_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} montgomery_ladder_curve_bench_metrics_t;
