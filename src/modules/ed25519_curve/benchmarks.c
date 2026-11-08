/**
 * Microbenchmark harness and cycle latency profiling for Twisted Edwards Curve Ed25519 Point Addition Laws.
 * Module: ed25519_curve
 */

#ifndef BENCH_ED25519_CURVE_H
#define BENCH_ED25519_CURVE_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct ed25519_curve_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} ed25519_curve_bench_metrics_t;

#endif /* BENCH_ED25519_CURVE_H */
