#include "interface.h"
#include <pthread.h>
#include <string.h>

typedef struct {
    const aes128_ctx_t* ctx;
    const uint8_t* in;
    uint8_t* out;
    size_t s;
    size_t e;
} aes_job_t;

static void* aes_worker(void* arg) {
    aes_job_t* j = (aes_job_t*)arg;
    for (size_t b = j->s; b < j->e; ++b) {
        uint8_t ctr[16] = {0};
        ctr[12] = (uint8_t)(b >> 24);
        ctr[13] = (uint8_t)(b >> 16);
        ctr[14] = (uint8_t)(b >> 8);
        ctr[15] = (uint8_t)b;
        uint8_t ks[16];
        aes128_encrypt_block(j->ctx, ctr, ks);
        for (size_t i = 0; i < 16U; ++i) j->out[b * 16U + i] = j->in[b * 16U + i] ^ ks[i];
    }
    return NULL;
}

aes128_fips197_cipher_err_t aes128_batch_ctr_mt(const aes128_ctx_t* ctx, const uint8_t* in, uint8_t* out, size_t n_blocks, size_t num_threads) {
    if (!ctx || !in || !out) return AES128_FIPS197_CIPHER_ERR_NULL;
    if (n_blocks == 0) return AES128_FIPS197_CIPHER_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    aes_job_t args[4];
    size_t chunk = (n_blocks + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * chunk, e = s + chunk;
        if (e > n_blocks) e = n_blocks;
        args[t] = (aes_job_t){ctx, in, out, s, e};
        pthread_create(&th[t], NULL, aes_worker, &args[t]);
    }
    for (size_t t = 0; t < num_threads; ++t) pthread_join(th[t], NULL);
    return AES128_FIPS197_CIPHER_OK;
}
