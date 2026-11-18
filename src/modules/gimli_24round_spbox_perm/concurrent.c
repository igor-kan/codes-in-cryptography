#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} gimli_24round_spbox_perm_task_t;

static void* gimli_24round_spbox_perm_worker(void* raw) {
    gimli_24round_spbox_perm_task_t* t = (gimli_24round_spbox_perm_task_t*)raw;
    t->out = gimli_24round_spbox_perm_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t gimli_24round_spbox_perm_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    gimli_24round_spbox_perm_task_t ta = {a, na, 0};
    gimli_24round_spbox_perm_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, gimli_24round_spbox_perm_worker, &ta);
    pthread_create(&th2, NULL, gimli_24round_spbox_perm_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
