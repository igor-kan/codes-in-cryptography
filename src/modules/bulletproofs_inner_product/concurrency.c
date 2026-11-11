/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct bulletproofs_inner_product_sync_counter {
    volatile uint64_t count;
} bulletproofs_inner_product_sync_counter_t;

static inline void bulletproofs_inner_product_sync_inc_v47(bulletproofs_inner_product_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
