/**
 * Microbenchmark harness and cycle latency profiling for Constant-Time ChaCha20 Quarter-Round Permutation.
 * Module: chacha20_stream
 */

#ifndef BENCH_CHACHA20_STREAM_H
#define BENCH_CHACHA20_STREAM_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct chacha20_stream_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} chacha20_stream_bench_metrics_t;

#endif /* BENCH_CHACHA20_STREAM_H */
