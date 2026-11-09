/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Parallel Tree-Hashing BLAKE3 Compression Function.
 * Module: blake3_tree_hash
 */

#include <stdint.h>

#define BLAKE3_TREE_HASH_BENCH_SAMPLES 100000

typedef struct blake3_tree_hash_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} blake3_tree_hash_bench_stats_t;
