/**
 * Microbenchmark harness and cycle latency profiling for Kate Polynomial Commitment and Proof Verification.
 * Module: kzg_commitments
 */

#ifndef BENCH_KZG_COMMITMENTS_H
#define BENCH_KZG_COMMITMENTS_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct kzg_commitments_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} kzg_commitments_bench_metrics_t;

#endif /* BENCH_KZG_COMMITMENTS_H */
