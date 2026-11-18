#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} fletcher64_adler32_dual_task_t;

static void* fletcher64_adler32_dual_worker(void* raw) {
    fletcher64_adler32_dual_task_t* t = (fletcher64_adler32_dual_task_t*)raw;
    t->out = fletcher64_adler32_dual_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t fletcher64_adler32_dual_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    fletcher64_adler32_dual_task_t ta = {a, na, 0};
    fletcher64_adler32_dual_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, fletcher64_adler32_dual_worker, &ta);
    pthread_create(&th2, NULL, fletcher64_adler32_dual_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
