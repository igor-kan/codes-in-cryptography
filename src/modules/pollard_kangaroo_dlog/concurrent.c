#include "interface.h"
#include <pthread.h>

typedef struct { uint64_t g; const uint64_t* t; size_t lo; size_t hi; uint64_t p; uint64_t a; uint64_t b; dlog_result_t* out; } kg_arg_t;

static void* kg_worker(void* raw) {
    kg_arg_t* arg = (kg_arg_t*)raw;
    for (size_t i = arg->lo; i < arg->hi; ++i) {
        arg->out[i] = kangaroo_solve(arg->g, arg->t[i], arg->p, arg->a, arg->b);
    }
    return NULL;
}

void parallel_kangaroo_solve(uint64_t g, const uint64_t* targets, size_t n, uint64_t p, uint64_t lo, uint64_t hi, dlog_result_t* out) {
    size_t mid = n / 2;
    kg_arg_t args[2] = {{g, targets, 0, mid, p, lo, hi, out}, {g, targets, mid, n, p, lo, hi, out}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, kg_worker, &args[0]);
    pthread_create(&t2, NULL, kg_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
