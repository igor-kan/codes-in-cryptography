#include "interface.h"
#include <pthread.h>

typedef struct { kek128_t kek; const uint64_t* pt; size_t n; uint64_t* ct; } kw_arg_t;

static void* kw_worker(void* raw) {
    kw_arg_t* a = (kw_arg_t*)raw;
    rfc3394_wrap(a->kek, a->pt, a->n, a->ct);
    return NULL;
}

void rfc3394_parallel_wrap(kek128_t kek, const uint64_t* cek_a, const uint64_t* cek_b, size_t n, uint64_t* out_a, uint64_t* out_b) {
    kw_arg_t args[2] = {{kek, cek_a, n, out_a}, {kek, cek_b, n, out_b}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, kw_worker, &args[0]);
    pthread_create(&t2, NULL, kw_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
