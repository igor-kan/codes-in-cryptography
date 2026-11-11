/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Constant-Time Modular Inverse via Bernstein-Yang Ladder.
 * Module: constant_time_mod_inv
 */

#include <stdint.h>

#define CONSTANT_TIME_MOD_INV_BENCH_SAMPLES 100000

typedef struct constant_time_mod_inv_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} constant_time_mod_inv_bench_stats_t;
