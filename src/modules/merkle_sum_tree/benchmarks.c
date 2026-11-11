/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#include <stdint.h>

#define MERKLE_SUM_TREE_BENCH_SAMPLES 100000

typedef struct merkle_sum_tree_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} merkle_sum_tree_bench_stats_t;
