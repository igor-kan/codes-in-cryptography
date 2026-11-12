/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression
 */

#include <stdint.h>

#define BLAKE2S_COMPRESSION_BENCH_CYCLES 100000

typedef struct blake2s_compression_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} blake2s_compression_profile_results_t;
