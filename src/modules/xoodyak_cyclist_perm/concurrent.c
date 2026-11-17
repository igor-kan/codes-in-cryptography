#include "interface.h"
#include <pthread.h>

typedef struct { const uint8_t* key; const uint8_t* msgs; size_t stride; size_t lo; size_t hi; uint8_t* tags; } xoo_arg_t;

static void* xoo_worker(void* raw) {
    xoo_arg_t* a = (xoo_arg_t*)raw;
    for (size_t i = a->lo; i < a->hi; ++i) {
        xoodyak_duplex_tag(a->key, 16, a->msgs + i * a->stride, a->stride, a->tags + i * 16);
    }
    return NULL;
}

void xoodyak_parallel_macs(const uint8_t key[16], const uint8_t* msgs, size_t stride, size_t count, uint8_t* out_tags) {
    size_t mid = count / 2;
    xoo_arg_t args[2] = {{key, msgs, stride, 0, mid, out_tags}, {key, msgs, stride, mid, count, out_tags}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, xoo_worker, &args[0]);
    pthread_create(&t2, NULL, xoo_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
