#include "interface.h"
#include <pthread.h>

typedef struct {
    const chaskey_ctx_t* ctx;
    const uint8_t** msgs;
    const size_t* lens;
    const uint8_t* tags;
    size_t s;
    size_t e;
    int ok;
} ch_job_t;

static void* ch_worker(void* arg) {
    ch_job_t* j = (ch_job_t*)arg;
    for (size_t i = j->s; i < j->e; ++i) {
        if (!chaskey_verify_ct(j->ctx, j->msgs[i], j->lens[i], j->tags + i * 16U)) j->ok = 0;
    }
    return NULL;
}

chaskey_mac_128_err_t chaskey_batch_verify_mt(const chaskey_ctx_t* ctx, const uint8_t** msgs, const size_t* lens, const uint8_t* tags, size_t count, size_t num_threads) {
    if (!ctx || !msgs || !lens || !tags) return CHASKEY_MAC_128_ERR_NULL;
    if (count == 0) return CHASKEY_MAC_128_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    ch_job_t args[4];
    size_t step = (count + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * step, e = s + step;
        if (e > count) e = count;
        args[t] = (ch_job_t){ctx, msgs, lens, tags, s, e, 1};
        pthread_create(&th[t], NULL, ch_worker, &args[t]);
    }
    int ok = 1;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        if (!args[t].ok) ok = 0;
    }
    return ok ? CHASKEY_MAC_128_OK : CHASKEY_MAC_128_ERR_INVARIANT;
}
