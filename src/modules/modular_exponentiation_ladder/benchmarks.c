/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder
 */

#include <stdint.h>

#define MODULAR_EXPONENTIATION_LADDER_BENCH_ITERATIONS 100000

typedef struct modular_exponentiation_ladder_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} modular_exponentiation_ladder_bench_metrics_t;
