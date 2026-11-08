/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

#include <stdint.h>

#define DILITHIUM_POLY_MUL_BENCH_ITERATIONS 100000

typedef struct dilithium_poly_mul_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} dilithium_poly_mul_bench_result_t;
