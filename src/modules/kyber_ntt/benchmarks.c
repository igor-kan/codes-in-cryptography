/**
 * Microbenchmark harness and cycle latency profiling for Number Theoretic Transform for ML-KEM Polynomial Arithmetic.
 * Module: kyber_ntt
 */

#ifndef BENCH_KYBER_NTT_H
#define BENCH_KYBER_NTT_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct kyber_ntt_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} kyber_ntt_bench_metrics_t;

#endif /* BENCH_KYBER_NTT_H */
