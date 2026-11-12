/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder
 */

#include <stdint.h>

#define POLY1305_CLAMP_LADDER_BENCH_CYCLES 100000

typedef struct poly1305_clamp_ladder_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} poly1305_clamp_ladder_profile_results_t;
