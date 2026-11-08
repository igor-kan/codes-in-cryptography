/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#include <stdint.h>

#define AES_GCM_GFMUL_BENCH_ITERATIONS 100000

typedef struct aes_gcm_gfmul_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} aes_gcm_gfmul_bench_result_t;
