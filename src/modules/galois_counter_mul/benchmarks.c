/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul
 */

#include <stdint.h>

#define GALOIS_COUNTER_MUL_BENCH_CYCLES 100000

typedef struct galois_counter_mul_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} galois_counter_mul_profile_results_t;
