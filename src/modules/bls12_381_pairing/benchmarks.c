/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#include <stdint.h>

#define BLS12_381_PAIRING_BENCH_SAMPLES 100000

typedef struct bls12_381_pairing_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} bls12_381_pairing_bench_stats_t;
