/**
 * Microbenchmark harness and cycle latency profiling for Keccak-f[1600] Cryptographic Sponge Permutation.
 * Module: sha3_sponge
 */

#ifndef BENCH_SHA3_SPONGE_H
#define BENCH_SHA3_SPONGE_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct sha3_sponge_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} sha3_sponge_bench_metrics_t;

#endif /* BENCH_SHA3_SPONGE_H */
