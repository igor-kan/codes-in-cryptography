#include "interface.h"

static const uint8_t SBOX[16] = {0xC,0x5,0x6,0xB,0x9,0x0,0xA,0xD,0x3,0xE,0xF,0x8,0x4,0x7,0x1,0x2};
static const uint8_t INV_SBOX[16] = {0x5,0xE,0xF,0x8,0xC,0x1,0x2,0xD,0xB,0x4,0x6,0x3,0x0,0x7,0x9,0xA};

static uint64_t sbox_layer(uint64_t s, const uint8_t box[16]) {
    uint64_t out = 0;
    for (int i = 0; i < 16; ++i) {
        out |= (uint64_t)box[(s >> (4 * i)) & 0xFU] << (4 * i);
    }
    return out;
}

static uint64_t p_layer(uint64_t s) {
    uint64_t out = 0;
    for (int i = 0; i < 63; ++i) {
        int dst = (16 * i) % 63;
        out |= ((s >> i) & 1ULL) << dst;
    }
    out |= s & (1ULL << 63);
    return out;
}

static uint64_t inv_p_layer(uint64_t s) {
    uint64_t out = 0;
    for (int i = 0; i < 63; ++i) {
        int dst = (16 * i) % 63;
        out |= ((s >> dst) & 1ULL) << i;
    }
    out |= s & (1ULL << 63);
    return out;
}

void present80_key_init(present80_key_t* ks, uint64_t key_hi, uint16_t key_lo) {
    uint64_t hi = key_hi;
    uint16_t lo = key_lo;
    for (int r = 1; r <= 32; ++r) {
        ks->rk[r - 1] = hi;
        if (r == 32) break;
        // 80-bit left rotation by 61 bits == right rotation by 19 bits
        uint64_t new_hi = (hi >> 19) | ((uint64_t)(lo & 0xFFFFU) << 45) | ((hi & 0x7ULL) << 61);
        uint16_t new_lo = (uint16_t)((hi >> 3) & 0xFFFFU);
        hi = new_hi;
        lo = new_lo;
        uint64_t top_nib = SBOX[(hi >> 60) & 0xFU];
        hi = (hi & 0x0FFFFFFFFFFFFFFFULL) | (top_nib << 60);
        lo ^= (uint16_t)((r & 1) << 15);
        hi ^= (uint64_t)(r >> 1);
    }
}

uint64_t present80_encrypt(const present80_key_t* ks, uint64_t state) {
    for (int r = 0; r < 31; ++r) {
        state ^= ks->rk[r];
        state = sbox_layer(state, SBOX);
        state = p_layer(state);
    }
    return state ^ ks->rk[31];
}

uint64_t present80_decrypt(const present80_key_t* ks, uint64_t state) {
    state ^= ks->rk[31];
    for (int r = 30; r >= 0; --r) {
        state = inv_p_layer(state);
        state = sbox_layer(state, INV_SBOX);
        state ^= ks->rk[r];
    }
    return state;
}
