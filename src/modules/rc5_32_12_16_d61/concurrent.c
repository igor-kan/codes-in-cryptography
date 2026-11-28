#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} rc5_32_12_16_d61_task_t;

static void* rc5_32_12_16_d61_worker(void* raw) {
    rc5_32_12_16_d61_task_t* t = (rc5_32_12_16_d61_task_t*)raw;
    t->out = rc5_32_12_16_d61_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t rc5_32_12_16_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    rc5_32_12_16_d61_task_t ta = {a, na, 0};
    rc5_32_12_16_d61_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, rc5_32_12_16_d61_worker, &ta);
    pthread_create(&th2, NULL, rc5_32_12_16_d61_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
