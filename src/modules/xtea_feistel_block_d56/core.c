#include "interface.h"
#include <math.h>
#include <string.h>

void xtea_encrypt_block(uint32_t v[2], const uint32_t key[4]) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0;
    const uint32_t delta = 0x9E3779B9u;
    for (int i = 0; i < 32; ++i) {
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3u]);
        sum += delta;
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum >> 11) & 3u]);
    }
    v[0] = v0;
    v[1] = v1;
}

void xtea_decrypt_block(uint32_t v[2], const uint32_t key[4]) {
    uint32_t v0 = v[0], v1 = v[1];
    const uint32_t delta = 0x9E3779B9u;
    uint32_t sum = delta * 32u;
    for (int i = 0; i < 32; ++i) {
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum >> 11) & 3u]);
        sum -= delta;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3u]);
    }
    v[0] = v0;
    v[1] = v1;
}
