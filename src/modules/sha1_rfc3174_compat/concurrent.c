#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint8_t** inputs;
    const size_t* lens;
    uint8_t* out20;
    size_t s;
    size_t e;
} sha1_job_t;

static void* sha1_worker(void* arg) {
    sha1_job_t* j = (sha1_job_t*)arg;
    for (size_t i = j->s; i < j->e; ++i) sha1_oneshot(j->inputs[i], j->lens[i], j->out20 + i * 20U);
    return NULL;
}

sha1_rfc3174_compat_err_t sha1_batch_hash_mt(const uint8_t** inputs, const size_t* lens, uint8_t* out20, size_t n_items, size_t num_threads) {
    if (!inputs || !lens || !out20) return SHA1_RFC3174_COMPAT_ERR_NULL;
    if (n_items == 0) return SHA1_RFC3174_COMPAT_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    sha1_job_t args[4];
    size_t step = (n_items + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * step, e = s + step;
        if (e > n_items) e = n_items;
        args[t] = (sha1_job_t){inputs, lens, out20, s, e};
        pthread_create(&th[t], NULL, sha1_worker, &args[t]);
    }
    for (size_t t = 0; t < num_threads; ++t) pthread_join(th[t], NULL);
    return SHA1_RFC3174_COMPAT_OK;
}
