#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} pbkdf2_iterated_stretch_d56_task_t;

static void* pbkdf2_iterated_stretch_d56_worker(void* raw) {
    pbkdf2_iterated_stretch_d56_task_t* t = (pbkdf2_iterated_stretch_d56_task_t*)raw;
    t->out = pbkdf2_iterated_stretch_d56_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t pbkdf2_iterated_stretch_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    pbkdf2_iterated_stretch_d56_task_t ta = {a, na, 0};
    pbkdf2_iterated_stretch_d56_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, pbkdf2_iterated_stretch_d56_worker, &ta);
    pthread_create(&th2, NULL, pbkdf2_iterated_stretch_d56_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
