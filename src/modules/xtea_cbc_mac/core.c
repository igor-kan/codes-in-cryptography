#include "interface.h"

void xtea_cbc_mac_encrypt_block(const xtea_key_t* key, uint32_t v[2]) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0;
    for (uint32_t i = 0; i < XTEA_ROUNDS; ++i) {
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key->k[sum & 3U]);
        sum += XTEA_DELTA;
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key->k[(sum >> 11) & 3U]);
    }
    v[0] = v0; v[1] = v1;
}

void xtea_cbc_mac_decrypt_block(const xtea_key_t* key, uint32_t v[2]) {
    uint32_t v0 = v[0], v1 = v[1], sum = XTEA_DELTA * XTEA_ROUNDS;
    for (uint32_t i = 0; i < XTEA_ROUNDS; ++i) {
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key->k[(sum >> 11) & 3U]);
        sum -= XTEA_DELTA;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key->k[sum & 3U]);
    }
    v[0] = v0; v[1] = v1;
}

xtea_cbc_mac_err_t xtea_cbc_mac_compute(const xtea_key_t* key, const uint8_t* msg, size_t blocks8, uint8_t tag[8]) {
    if (!key || !msg || !tag || blocks8 == 0) return XTEA_CBC_MAC_ERR_NULL;
    uint32_t chain[2] = {0, 0};
    for (size_t b = 0; b < blocks8; ++b) {
        const uint8_t* p = msg + b * 8;
        uint32_t m0 = (uint32_t)p[0] | ((uint32_t)p[1]<<8) | ((uint32_t)p[2]<<16) | ((uint32_t)p[3]<<24);
        uint32_t m1 = (uint32_t)p[4] | ((uint32_t)p[5]<<8) | ((uint32_t)p[6]<<16) | ((uint32_t)p[7]<<24);
        chain[0] ^= m0; chain[1] ^= m1;
        xtea_cbc_mac_encrypt_block(key, chain);
    }
    for (int i = 0; i < 4; ++i) {
        tag[i] = (uint8_t)(chain[0] >> (8 * i));
        tag[4 + i] = (uint8_t)(chain[1] >> (8 * i));
    }
    return XTEA_CBC_MAC_OK;
}
