#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} feistel_luby_rackoff_c11_task_t;

static void* feistel_luby_rackoff_c11_worker(void* raw) {
    feistel_luby_rackoff_c11_task_t* t = (feistel_luby_rackoff_c11_task_t*)raw;
    t->out = feistel_luby_rackoff_c11_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t feistel_luby_rackoff_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    feistel_luby_rackoff_c11_task_t ta = {a, na, 0};
    feistel_luby_rackoff_c11_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, feistel_luby_rackoff_c11_worker, &ta);
    pthread_create(&th2, NULL, feistel_luby_rackoff_c11_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
