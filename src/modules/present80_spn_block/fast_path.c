#include "interface.h"

uint64_t present80_fast_cbc_mac(const present80_key_t* ks, const uint64_t* blocks, size_t n) {
    uint64_t mac = 0;
    for (size_t i = 0; i < n; ++i) mac = present80_encrypt(ks, mac ^ blocks[i]);
    return mac;
}
