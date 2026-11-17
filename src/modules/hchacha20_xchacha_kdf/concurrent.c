#include "interface.h"
#include <pthread.h>

typedef struct { const uint8_t* k; const uint8_t* n; size_t lo; size_t hi; uint8_t* out; } hc_arg_t;

static void* hc_worker(void* raw) {
    hc_arg_t* a = (hc_arg_t*)raw;
    for (size_t i = a->lo; i < a->hi; ++i) {
        hchacha20_derive(a->k, a->n + 16 * i, a->out + 32 * i);
    }
    return NULL;
}

void hchacha20_parallel_derive(const uint8_t key[32], const uint8_t* nonces16, size_t count, uint8_t* out_keys32) {
    size_t mid = count / 2;
    hc_arg_t args[2] = {{key, nonces16, 0, mid, out_keys32}, {key, nonces16, mid, count, out_keys32}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, hc_worker, &args[0]);
    pthread_create(&t2, NULL, hc_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
