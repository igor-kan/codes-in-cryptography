#include "interface.h"
#include <math.h>
#include <string.h>

int jacobi_symbol(uint64_t a, uint64_t n) {
    if (n == 0 || (n & 1ULL) == 0) return 0;
    a %= n;
    int t = 1;
    while (a != 0) {
        while ((a & 1ULL) == 0) {
            a >>= 1;
            uint64_t r = n & 7ULL;
            if (r == 3 || r == 5) t = -t;
        }
        uint64_t tmp = a; a = n; n = tmp;
        if ((a & 3ULL) == 3 && (n & 3ULL) == 3) t = -t;
        a %= n;
    }
    return n == 1 ? t : 0;
}
static uint64_t ss_pow(uint64_t b, uint64_t e, uint64_t m) {
    uint64_t r = 1; b %= m;
    while (e > 0) {
        if (e & 1ULL) r = (uint64_t)(((__uint128_t)r * b) % m);
        b = (uint64_t)(((__uint128_t)b * b) % m);
        e >>= 1;
    }
    return r;
}
bool solovay_strassen_prime(uint64_t n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if ((n & 1ULL) == 0) return false;
    const uint64_t bases[7] = {2, 3, 5, 7, 11, 13, 17};
    for (int i = 0; i < 7; ++i) {
        uint64_t a = bases[i];
        if (a >= n) break;
        int j = jacobi_symbol(a, n);
        if (j == 0) return false;
        uint64_t rhs = (j == -1) ? (n - 1) : 1ULL;
        if (ss_pow(a, (n - 1) / 2, n) != rhs) return false;
    }
    return true;
}
