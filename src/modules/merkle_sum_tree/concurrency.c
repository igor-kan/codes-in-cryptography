/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct merkle_sum_tree_sync_counter {
    volatile uint64_t count;
} merkle_sum_tree_sync_counter_t;

static inline void merkle_sum_tree_sync_inc_v47(merkle_sum_tree_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
