#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} gf128_ghash_mul_d60_task_t;

static void* gf128_ghash_mul_d60_worker(void* raw) {
    gf128_ghash_mul_d60_task_t* t = (gf128_ghash_mul_d60_task_t*)raw;
    t->out = gf128_ghash_mul_d60_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t gf128_ghash_mul_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    gf128_ghash_mul_d60_task_t ta = {a, na, 0};
    gf128_ghash_mul_d60_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, gf128_ghash_mul_d60_worker, &ta);
    pthread_create(&th2, NULL, gf128_ghash_mul_d60_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
