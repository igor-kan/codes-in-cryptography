/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead
 */

#include <stdint.h>

#define CHACHA20_POLY1305_AEAD_BENCH_ITERATIONS 100000

typedef struct chacha20_poly1305_aead_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} chacha20_poly1305_aead_bench_metrics_t;
