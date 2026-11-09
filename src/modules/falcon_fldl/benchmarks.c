/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Falcon Lattice Fast Fourier Orthogonalization (LDL).
 * Module: falcon_fldl
 */

#include <stdint.h>

#define FALCON_FLDL_BENCH_SAMPLES 100000

typedef struct falcon_fldl_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} falcon_fldl_bench_stats_t;
