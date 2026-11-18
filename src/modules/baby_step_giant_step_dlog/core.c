#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t bsgs_pow_mod(uint64_t b, uint64_t e, uint64_t p) {
    uint64_t r = 1; b %= p;
    while (e > 0) {
        if (e & 1ULL) r = (r * b) % p;
        b = (b * b) % p;
        e >>= 1;
    }
    return r;
}
int64_t shanks_bsgs_dlog(uint64_t g, uint64_t h, uint64_t p) {
    uint32_t m = (uint32_t)sqrt((double)p) + 1U;
    bsgs_pair_t tbl[512];
    uint64_t cur = 1;
    for (uint32_t j = 0; j < m && j < 512; ++j) {
        tbl[j] = (bsgs_pair_t){cur, j};
        cur = (cur * g) % p;
    }
    uint64_t gm_inv = bsgs_pow_mod(bsgs_pow_mod(g, m, p), p - 2, p);
    uint64_t gamma = h % p;
    for (uint32_t i = 0; i <= m; ++i) {
        for (uint32_t j = 0; j < m && j < 512; ++j) {
            if (tbl[j].val == gamma) return (int64_t)i * m + tbl[j].idx;
        }
        gamma = (gamma * gm_inv) % p;
    }
    return -1;
}
