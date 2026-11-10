/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for SIMD-Accelerated BLAKE2b Cryptographic Hashing Engine.
 * Module: blake2b_simd
 */

#include <stdint.h>

#define BLAKE2B_SIMD_BENCH_SAMPLES 100000

typedef struct blake2b_simd_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} blake2b_simd_bench_stats_t;
