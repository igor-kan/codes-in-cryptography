/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Constant-Time Tonelli-Shanks Quadratic Residue Solver.
 * Module: modular_sqrt_tonelli
 */

#include <stdint.h>

#define MODULAR_SQRT_TONELLI_BENCH_SAMPLES 100000

typedef struct modular_sqrt_tonelli_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} modular_sqrt_tonelli_bench_stats_t;
