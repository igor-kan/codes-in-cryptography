#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint8_t* prk;
    size_t s;
    size_t e;
    size_t okm_len;
    uint8_t* out_flat;
    int ok;
} hkdf_job_t;

static void* hkdf_worker(void* arg) {
    hkdf_job_t* j = (hkdf_job_t*)arg;
    for (size_t i = j->s; i < j->e; ++i) {
        uint8_t info[4] = {(uint8_t)(i >> 24), (uint8_t)(i >> 16), (uint8_t)(i >> 8), (uint8_t)i};
        if (hkdf_expand(j->prk, info, 4, j->out_flat + i * j->okm_len, j->okm_len) != HKDF_SHA256_RFC5869_OK) {
            j->ok = 0;
        }
    }
    return NULL;
}

hkdf_sha256_rfc5869_err_t hkdf_batch_derive_mt(const uint8_t prk[32], size_t count, size_t okm_len, uint8_t* out_flat, size_t num_threads) {
    if (!prk || !out_flat) return HKDF_SHA256_RFC5869_ERR_NULL;
    if (count == 0) return HKDF_SHA256_RFC5869_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    hkdf_job_t args[4];
    size_t chunk = (count + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * chunk, e = s + chunk;
        if (e > count) e = count;
        args[t] = (hkdf_job_t){prk, s, e, okm_len, out_flat, 1};
        pthread_create(&th[t], NULL, hkdf_worker, &args[t]);
    }
    int ok = 1;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        if (!args[t].ok) ok = 0;
    }
    return ok ? HKDF_SHA256_RFC5869_OK : HKDF_SHA256_RFC5869_ERR_INVARIANT;
}
