/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct merkle_patricia_trie_sync_counter {
    volatile uint64_t count;
} merkle_patricia_trie_sync_counter_t;

static inline void merkle_patricia_trie_sync_inc(merkle_patricia_trie_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
