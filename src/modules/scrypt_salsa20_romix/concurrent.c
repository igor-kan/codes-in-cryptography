#include "interface.h"
#include <pthread.h>

typedef struct { uint32_t* B; uint32_t* V; size_t r; size_t N; } ro_arg_t;

static void* ro_worker(void* raw) {
    ro_arg_t* a = (ro_arg_t*)raw;
    scrypt_romix(a->B, a->r, a->N, a->V);
    return NULL;
}

void scrypt_parallel_romix(uint32_t* B1, uint32_t* V1, uint32_t* B2, uint32_t* V2, size_t r, size_t N) {
    ro_arg_t args[2] = {{B1, V1, r, N}, {B2, V2, r, N}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, ro_worker, &args[0]);
    pthread_create(&t2, NULL, ro_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
