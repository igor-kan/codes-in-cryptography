/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#include <stdint.h>

#define SECP256K1_ECDSA_BENCH_SAMPLES 100000

typedef struct secp256k1_ecdsa_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} secp256k1_ecdsa_bench_stats_t;
