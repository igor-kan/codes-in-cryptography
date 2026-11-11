/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Memory-Hard Argon2d/Argon2i Block Mixing Permutation.
 * Module: argon2_password_hash
 */

#include <stdint.h>

#define ARGON2_PASSWORD_HASH_BENCH_SAMPLES 100000

typedef struct argon2_password_hash_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} argon2_password_hash_bench_stats_t;
