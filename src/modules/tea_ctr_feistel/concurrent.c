#include "interface.h"
#include <pthread.h>

typedef struct {
    const tea_key_t* key;
    size_t s;
    size_t e;
    int ok;
} tea_job_t;

static void* tea_worker(void* arg) {
    tea_job_t* j = (tea_job_t*)arg;
    for (size_t i = j->s; i < j->e; ++i) {
        if (tea_verify_involution(j->key, (uint32_t)i, (uint32_t)(i * 2654435761U)) != TEA_CTR_FEISTEL_OK) {
            j->ok = 0;
        }
    }
    return NULL;
}

tea_ctr_feistel_err_t tea_batch_roundtrip_mt(const tea_key_t* key, size_t n_blocks, size_t num_threads) {
    if (!key) return TEA_CTR_FEISTEL_ERR_NULL;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    tea_job_t args[4];
    size_t step = (n_blocks + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * step, e = s + step;
        if (e > n_blocks) e = n_blocks;
        args[t] = (tea_job_t){key, s, e, 1};
        pthread_create(&th[t], NULL, tea_worker, &args[t]);
    }
    int ok = 1;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        if (!args[t].ok) ok = 0;
    }
    return ok ? TEA_CTR_FEISTEL_OK : TEA_CTR_FEISTEL_ERR_INVARIANT;
}
