#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} baby_step_giant_step_dlog_task_t;

static void* baby_step_giant_step_dlog_worker(void* raw) {
    baby_step_giant_step_dlog_task_t* t = (baby_step_giant_step_dlog_task_t*)raw;
    t->out = baby_step_giant_step_dlog_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t baby_step_giant_step_dlog_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    baby_step_giant_step_dlog_task_t ta = {a, na, 0};
    baby_step_giant_step_dlog_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, baby_step_giant_step_dlog_worker, &ta);
    pthread_create(&th2, NULL, baby_step_giant_step_dlog_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
