#include "interface.h"

void tea_encrypt_block(const tea_key_t* key, uint32_t v[2]) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0;
    const uint32_t delta = 0x9E3779B9U;
    for (int i = 0; i < 32; ++i) {
        sum += delta;
        v0 += ((v1 << 4) + key->k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + key->k[1]);
        v1 += ((v0 << 4) + key->k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + key->k[3]);
    }
    v[0] = v0;
    v[1] = v1;
}

void tea_decrypt_block(const tea_key_t* key, uint32_t v[2]) {
    uint32_t v0 = v[0], v1 = v[1];
    const uint32_t delta = 0x9E3779B9U;
    uint32_t sum = 0xC6EF3720U; // 32 * delta mod 2^32
    for (int i = 0; i < 32; ++i) {
        v1 -= ((v0 << 4) + key->k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + key->k[3]);
        v0 -= ((v1 << 4) + key->k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + key->k[1]);
        sum -= delta;
    }
    v[0] = v0;
    v[1] = v1;
}
