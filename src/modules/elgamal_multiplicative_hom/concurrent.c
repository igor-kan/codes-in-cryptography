#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} elgamal_multiplicative_hom_task_t;

static void* elgamal_multiplicative_hom_worker(void* raw) {
    elgamal_multiplicative_hom_task_t* t = (elgamal_multiplicative_hom_task_t*)raw;
    t->out = elgamal_multiplicative_hom_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t elgamal_multiplicative_hom_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    elgamal_multiplicative_hom_task_t ta = {a, na, 0};
    elgamal_multiplicative_hom_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, elgamal_multiplicative_hom_worker, &ta);
    pthread_create(&th2, NULL, elgamal_multiplicative_hom_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
