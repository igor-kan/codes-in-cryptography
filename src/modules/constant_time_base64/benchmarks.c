/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Side-Channel Immune Constant-Time Base64 Engine.
 * Module: constant_time_base64
 */

#include <stdint.h>

#define CONSTANT_TIME_BASE64_BENCH_SAMPLES 100000

typedef struct constant_time_base64_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} constant_time_base64_bench_stats_t;
