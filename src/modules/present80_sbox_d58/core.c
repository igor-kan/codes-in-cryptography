#include "interface.h"
#include <math.h>
#include <string.h>

static const uint8_t PRESENT_S[16] = {12,5,6,11,9,0,10,13,3,14,15,8,4,7,1,2};
static const uint8_t PRESENT_IS[16] = {5,14,15,8,12,1,2,13,11,4,6,3,0,7,9,10};

uint64_t spn_apply_sbox(uint64_t x) {
    uint64_t out = 0;
    for (int i = 0; i < 16; ++i) {
        out |= ((uint64_t)PRESENT_S[(x >> (4 * i)) & 0xFu]) << (4 * i);
    }
    return out;
}

uint64_t spn_inv_sbox(uint64_t x) {
    uint64_t out = 0;
    for (int i = 0; i < 16; ++i) {
        out |= ((uint64_t)PRESENT_IS[(x >> (4 * i)) & 0xFu]) << (4 * i);
    }
    return out;
}

uint64_t spn_permute64(uint64_t x) {
    uint64_t out = 0;
    for (int i = 0; i < 64; ++i) {
        int dst = (i == 63) ? 63 : (i * 16) % 63;
        out |= ((x >> i) & 1ULL) << dst;
    }
    return out;
}

uint64_t spn_inv_permute64(uint64_t x) {
    uint64_t out = 0;
    for (int i = 0; i < 64; ++i) {
        int dst = (i == 63) ? 63 : (i * 16) % 63;
        out |= ((x >> dst) & 1ULL) << i;
    }
    return out;
}
