/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Parallel Tree-Hashing BLAKE3 Compression Function.
 * Module: blake3_tree_hash
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct blake3_tree_hash_sync_counter {
    volatile uint64_t count;
} blake3_tree_hash_sync_counter_t;

static inline void blake3_tree_hash_sync_inc(blake3_tree_hash_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
