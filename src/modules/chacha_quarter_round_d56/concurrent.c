#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} chacha_quarter_round_d56_task_t;

static void* chacha_quarter_round_d56_worker(void* raw) {
    chacha_quarter_round_d56_task_t* t = (chacha_quarter_round_d56_task_t*)raw;
    t->out = chacha_quarter_round_d56_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t chacha_quarter_round_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    chacha_quarter_round_d56_task_t ta = {a, na, 0};
    chacha_quarter_round_d56_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, chacha_quarter_round_d56_worker, &ta);
    pthread_create(&th2, NULL, chacha_quarter_round_d56_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
