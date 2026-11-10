/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#include <stdint.h>

#define ML_KEM_POLY_VECTOR_BENCH_SAMPLES 100000

typedef struct ml_kem_poly_vector_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} ml_kem_poly_vector_bench_stats_t;
