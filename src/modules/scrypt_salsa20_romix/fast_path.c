#include "interface.h"

void scrypt_fast_xor32(uint32_t* dst, const uint32_t* a, const uint32_t* b, size_t words) {
    for (size_t i = 0; i < words; ++i) dst[i] = a[i] ^ b[i];
}
