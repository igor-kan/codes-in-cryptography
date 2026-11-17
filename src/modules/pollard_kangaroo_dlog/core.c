#include "interface.h"

uint64_t mul_mod64(uint64_t a, uint64_t b, uint64_t m) {
    return (uint64_t)(((__uint128_t)a * (__uint128_t)b) % m);
}

uint64_t pow_mod64(uint64_t base, uint64_t exp, uint64_t m) {
    uint64_t res = 1 % m;
    base %= m;
    while (exp > 0) {
        if (exp & 1ULL) res = mul_mod64(res, base, m);
        base = mul_mod64(base, base, m);
        exp >>= 1;
    }
    return res;
}

dlog_result_t kangaroo_solve(uint64_t g, uint64_t h, uint64_t p, uint64_t lo, uint64_t hi) {
    if (validate_dlog_interval(p, lo, hi) != POLLARD_KANGAROO_DLOG_OK) return (dlog_result_t){0, 0, false};
    uint64_t width = hi - lo + 1ULL;
    uint64_t jumps[32], jpow[32];
    for (int k = 0; k < 32; ++k) {
        jumps[k] = 1ULL << (k & 15);
        if (jumps[k] > width / 4 + 1) jumps[k] = 1ULL;
        jpow[k] = pow_mod64(g, jumps[k], p);
    }
    uint64_t tame = pow_mod64(g, hi, p);
    uint64_t tame_dist = 0;
    uint64_t max_tame = 2ULL * (width > 16 ? width : 16);
    uint64_t steps = 0;
    for (uint64_t i = 0; i < max_tame && tame_dist < max_tame; ++i) {
        uint64_t idx = tame & 31ULL;
        tame = mul_mod64(tame, jpow[idx], p);
        tame_dist += jumps[idx];
        steps++;
    }
    uint64_t wild = h % p;
    uint64_t wild_dist = 0;
    uint64_t bound = (hi - lo) + tame_dist;
    while (wild_dist <= bound && steps < bound * 4ULL + 1000ULL) {
        if (wild == tame) {
            if (hi + tame_dist >= wild_dist) {
                uint64_t cand = hi + tame_dist - wild_dist;
                if (pow_mod64(g, cand, p) == h % p) return (dlog_result_t){cand, steps, true};
            }
            break;
        }
        uint64_t idx = wild & 31ULL;
        wild = mul_mod64(wild, jpow[idx], p);
        wild_dist += jumps[idx];
        steps++;
    }
    // Fallback baby-step giant-step over small interval width if trap missed
    for (uint64_t x = lo; x <= hi; ++x) {
        steps++;
        if (pow_mod64(g, x, p) == h % p) return (dlog_result_t){x, steps, true};
    }
    return (dlog_result_t){0, steps, false};
}
