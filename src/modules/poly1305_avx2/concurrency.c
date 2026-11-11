/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for AVX2-Accelerated Poly1305 Message Authentication Code.
 * Module: poly1305_avx2
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct poly1305_avx2_sync_counter {
    volatile uint64_t count;
} poly1305_avx2_sync_counter_t;

static inline void poly1305_avx2_sync_inc_v47(poly1305_avx2_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
