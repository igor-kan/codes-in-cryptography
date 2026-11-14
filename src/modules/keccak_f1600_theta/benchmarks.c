/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

#include <stdint.h>

#define KECCAK_F1600_THETA_BENCH_ITERATIONS 100000

typedef struct keccak_f1600_theta_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} keccak_f1600_theta_bench_metrics_t;
