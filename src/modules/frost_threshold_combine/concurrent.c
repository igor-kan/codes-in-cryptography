#include "interface.h"
#include <pthread.h>

typedef struct { const uint64_t* c; size_t deg; const uint64_t* ids; uint64_t* out; size_t lo; size_t hi; } ev_arg_t;

static uint64_t horner(const uint64_t* coeffs, size_t deg, uint64_t x) {
    uint64_t acc = 0;
    for (size_t i = deg + 1; i-- > 0;) acc = mod_add_q(mod_mul_q(acc, x), coeffs[i]);
    return acc;
}

static void* ev_worker(void* raw) {
    ev_arg_t* a = (ev_arg_t*)raw;
    for (size_t i = a->lo; i < a->hi; ++i) a->out[i] = horner(a->c, a->deg, a->ids[i]);
    return NULL;
}

void frost_parallel_eval_shares(const uint64_t* coeffs, size_t deg, const uint64_t* ids, uint64_t* out_shares, size_t n) {
    size_t mid = n / 2;
    ev_arg_t args[2] = {{coeffs, deg, ids, out_shares, 0, mid}, {coeffs, deg, ids, out_shares, mid, n}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, ev_worker, &args[0]);
    pthread_create(&t2, NULL, ev_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
