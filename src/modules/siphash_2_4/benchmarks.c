/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

#include <stdint.h>

#define SIPHASH_2_4_BENCH_ITERATIONS 100000

typedef struct siphash_2_4_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} siphash_2_4_bench_result_t;
