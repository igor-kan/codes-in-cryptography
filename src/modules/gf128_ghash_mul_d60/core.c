#include "interface.h"
#include <math.h>
#include <string.h>

gf128_elem_t gf128_mul_d60(gf128_elem_t x, gf128_elem_t y) {
    uint64_t z_hi = 0, z_lo = 0;
    uint64_t v_hi = y.hi, v_lo = y.lo;
    for (int i = 0; i < 128; ++i) {
        uint64_t bit = (i < 64) ? ((x.hi >> (63 - i)) & 1ULL) : ((x.lo >> (127 - i)) & 1ULL);
        uint64_t mask = -bit;
        z_hi ^= (v_hi & mask);
        z_lo ^= (v_lo & mask);
        uint64_t lsb = v_lo & 1ULL;
        v_lo = (v_lo >> 1) | (v_hi << 63);
        v_hi = (v_hi >> 1) ^ (-(lsb) & 0xe100000000000000ULL);
    }
    return (gf128_elem_t){z_hi, z_lo};
}
