#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} rc6_w32_r20_block_cipher_task_t;

static void* rc6_w32_r20_block_cipher_worker(void* raw) {
    rc6_w32_r20_block_cipher_task_t* t = (rc6_w32_r20_block_cipher_task_t*)raw;
    t->out = rc6_w32_r20_block_cipher_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t rc6_w32_r20_block_cipher_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    rc6_w32_r20_block_cipher_task_t ta = {a, na, 0};
    rc6_w32_r20_block_cipher_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, rc6_w32_r20_block_cipher_worker, &ta);
    pthread_create(&th2, NULL, rc6_w32_r20_block_cipher_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
