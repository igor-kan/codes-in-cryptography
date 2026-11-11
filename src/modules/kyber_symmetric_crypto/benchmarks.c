/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#include <stdint.h>

#define KYBER_SYMMETRIC_CRYPTO_BENCH_SAMPLES 100000

typedef struct kyber_symmetric_crypto_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} kyber_symmetric_crypto_bench_stats_t;
