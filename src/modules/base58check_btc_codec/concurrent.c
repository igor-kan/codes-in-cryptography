#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint8_t** payloads;
    const size_t* lens;
    size_t s;
    size_t e;
    int ok;
} b58_job_t;

static void* b58_worker(void* arg) {
    b58_job_t* j = (b58_job_t*)arg;
    for (size_t i = j->s; i < j->e; ++i) {
        if (b58_verify_invariants(j->payloads[i], j->lens[i]) != BASE58CHECK_BTC_CODEC_OK) j->ok = 0;
    }
    return NULL;
}

base58check_btc_codec_err_t b58_batch_verify_mt(const uint8_t** payloads, const size_t* lens, size_t count, size_t num_threads) {
    if (!payloads || !lens) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    if (count == 0) return BASE58CHECK_BTC_CODEC_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    b58_job_t args[4];
    size_t step = (count + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * step, e = s + step;
        if (e > count) e = count;
        args[t] = (b58_job_t){payloads, lens, s, e, 1};
        pthread_create(&th[t], NULL, b58_worker, &args[t]);
    }
    int ok = 1;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        if (!args[t].ok) ok = 0;
    }
    return ok ? BASE58CHECK_BTC_CODEC_OK : BASE58CHECK_BTC_CODEC_ERR_INVARIANT;
}
