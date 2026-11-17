#include "interface.h"
#include <pthread.h>

typedef struct { const present80_key_t* ks; uint64_t* b; size_t lo; size_t hi; } pr_arg_t;

static void* pr_worker(void* raw) {
    pr_arg_t* a = (pr_arg_t*)raw;
    for (size_t i = a->lo; i < a->hi; ++i) a->b[i] = present80_encrypt(a->ks, a->b[i]);
    return NULL;
}

void present80_parallel_encrypt(const present80_key_t* ks, uint64_t* blocks, size_t n) {
    size_t mid = n / 2;
    pr_arg_t args[2] = {{ks, blocks, 0, mid}, {ks, blocks, mid, n}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, pr_worker, &args[0]);
    pthread_create(&t2, NULL, pr_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
