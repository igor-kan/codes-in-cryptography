/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine
 */

#include <stdint.h>

#define SPONGE_DUPLEX_ENGINE_BENCH_CYCLES 100000

typedef struct sponge_duplex_engine_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} sponge_duplex_engine_profile_results_t;
