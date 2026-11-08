/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#include <stdint.h>

#define X25519_DIFFIE_HELLMAN_BENCH_ITERATIONS 100000

typedef struct x25519_diffie_hellman_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} x25519_diffie_hellman_bench_result_t;
