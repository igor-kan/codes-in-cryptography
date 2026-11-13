/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr
 */

#include <stdint.h>

#define CHACHA20_BLOCK_QR_BENCH_ITERATIONS 100000

typedef struct chacha20_block_qr_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} chacha20_block_qr_bench_metrics_t;
