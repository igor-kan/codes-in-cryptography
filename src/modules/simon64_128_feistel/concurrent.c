#include "interface.h"
#include <pthread.h>

typedef struct { const simon64_key_t* ks; uint64_t nonce; uint64_t* buf; size_t lo; size_t hi; } ctr_arg_t;

static void* ctr_worker(void* raw) {
    ctr_arg_t* a = (ctr_arg_t*)raw;
    for (size_t i = a->lo; i < a->hi; ++i) {
        uint64_t ctr = a->nonce ^ (uint64_t)i;
        uint32_t in[2] = {(uint32_t)ctr, (uint32_t)(ctr >> 32)}, ks_blk[2];
        simon64_encrypt_block(a->ks, in, ks_blk);
        a->buf[i] ^= ((uint64_t)ks_blk[1] << 32) | ks_blk[0];
    }
    return NULL;
}

void simon64_parallel_ctr(const simon64_key_t* ks, uint64_t nonce, uint64_t* buf, size_t n) {
    size_t mid = n / 2;
    ctr_arg_t args[2] = {{ks, nonce, buf, 0, mid}, {ks, nonce, buf, mid, n}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, ctr_worker, &args[0]);
    pthread_create(&t2, NULL, ctr_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
