/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#include <stdint.h>

#define MERKLE_PATRICIA_TRIE_BENCH_SAMPLES 100000

typedef struct merkle_patricia_trie_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} merkle_patricia_trie_bench_stats_t;
