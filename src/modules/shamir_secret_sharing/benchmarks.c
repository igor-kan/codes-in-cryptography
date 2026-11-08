/**
 * Microbenchmark harness and cycle latency profiling for GF(256) Lagrange Polynomial Secret Sharing Engine.
 * Module: shamir_secret_sharing
 */

#ifndef BENCH_SHAMIR_SECRET_SHARING_H
#define BENCH_SHAMIR_SECRET_SHARING_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct shamir_secret_sharing_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} shamir_secret_sharing_bench_metrics_t;

#endif /* BENCH_SHAMIR_SECRET_SHARING_H */
