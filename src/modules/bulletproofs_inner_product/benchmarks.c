/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

#include <stdint.h>

#define BULLETPROOFS_INNER_PRODUCT_BENCH_SAMPLES 100000

typedef struct bulletproofs_inner_product_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} bulletproofs_inner_product_bench_stats_t;
