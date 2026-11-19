#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t lr_prf(uint32_t rk, uint32_t r) {
    uint64_t x = ((uint64_t)(r ^ rk) + 0x9e3779b9U) * 0xbf58476d1ce4e5b9ULL;
    x ^= x >> 29;
    return (uint32_t)((x * 0x94d049bb133111ebULL) >> 32);
}
uint64_t lr_encrypt64(lr_key_t k, uint64_t pt) {
    uint32_t l = (uint32_t)(pt >> 32), r = (uint32_t)pt;
    for (int i = 0; i < 4; ++i) { uint32_t nl = r; r = l ^ lr_prf(k.rk[i], r); l = nl; }
    return ((uint64_t)l << 32) | r;
}
uint64_t lr_decrypt64(lr_key_t k, uint64_t ct) {
    uint32_t l = (uint32_t)(ct >> 32), r = (uint32_t)ct;
    for (int i = 3; i >= 0; --i) { uint32_t nr = l; l = r ^ lr_prf(k.rk[i], l); r = nr; }
    return ((uint64_t)l << 32) | r;
}
