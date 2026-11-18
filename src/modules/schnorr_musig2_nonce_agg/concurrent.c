#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} schnorr_musig2_nonce_agg_task_t;

static void* schnorr_musig2_nonce_agg_worker(void* raw) {
    schnorr_musig2_nonce_agg_task_t* t = (schnorr_musig2_nonce_agg_task_t*)raw;
    t->out = schnorr_musig2_nonce_agg_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t schnorr_musig2_nonce_agg_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    schnorr_musig2_nonce_agg_task_t ta = {a, na, 0};
    schnorr_musig2_nonce_agg_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, schnorr_musig2_nonce_agg_worker, &ta);
    pthread_create(&th2, NULL, schnorr_musig2_nonce_agg_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
