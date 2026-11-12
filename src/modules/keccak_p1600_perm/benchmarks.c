/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

#include <stdint.h>

#define KECCAK_P1600_PERM_BENCH_CYCLES 100000

typedef struct keccak_p1600_perm_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} keccak_p1600_perm_profile_results_t;
