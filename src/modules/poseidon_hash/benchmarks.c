/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Zero-Knowledge Friendly Algebraic Poseidon Hash.
 * Module: poseidon_hash
 */

#include <stdint.h>

#define POSEIDON_HASH_BENCH_SAMPLES 100000

typedef struct poseidon_hash_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} poseidon_hash_bench_stats_t;
