#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t mulm(uint64_t a, uint64_t b, uint64_t m) {
    return (uint64_t)(((__uint128_t)a * b) % m);
}

static uint64_t powm(uint64_t a, uint64_t d, uint64_t m) {
    uint64_t r = 1ULL;
    a %= m;
    while (d > 0) {
        if (d & 1ULL) r = mulm(r, a, m);
        a = mulm(a, a, m);
        d >>= 1;
    }
    return r;
}

int is_prime_u64(uint64_t n) {
    if (n < 2) return 0;
    static const uint64_t bases[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int i = 0; i < 12; ++i) {
        if (n == bases[i]) return 1;
        if (n % bases[i] == 0) return 0;
    }
    uint64_t d = n - 1; int s = 0;
    while ((d & 1ULL) == 0) { d >>= 1; ++s; }
    for (int i = 0; i < 12; ++i) {
        uint64_t x = powm(bases[i], d, n);
        if (x == 1 || x == n - 1) continue;
        int ok = 0;
        for (int r = 1; r < s; ++r) {
            x = mulm(x, x, n);
            if (x == n - 1) { ok = 1; break; }
        }
        if (!ok) return 0;
    }
    return 1;
}
