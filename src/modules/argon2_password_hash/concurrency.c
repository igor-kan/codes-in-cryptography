/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Memory-Hard Argon2d/Argon2i Block Mixing Permutation.
 * Module: argon2_password_hash
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct argon2_password_hash_sync_counter {
    volatile uint64_t count;
} argon2_password_hash_sync_counter_t;

static inline void argon2_password_hash_sync_inc_v47(argon2_password_hash_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
