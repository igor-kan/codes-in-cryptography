/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Luby-Rackoff 4-Round Balanced Feistel Block Cipher.
 * Module: feistel_cipher_round
 */

#include <stdint.h>

#define FEISTEL_CIPHER_ROUND_BENCH_CYCLES 100000

typedef struct feistel_cipher_round_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} feistel_cipher_round_profile_results_t;
