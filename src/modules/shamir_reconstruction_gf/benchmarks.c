/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Lagrange Interpolation Secret Reconstruction GF(256).
 * Module: shamir_reconstruction_gf
 */

#include <stdint.h>

#define SHAMIR_RECONSTRUCTION_GF_BENCH_ITERATIONS 100000

typedef struct shamir_reconstruction_gf_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} shamir_reconstruction_gf_bench_metrics_t;
