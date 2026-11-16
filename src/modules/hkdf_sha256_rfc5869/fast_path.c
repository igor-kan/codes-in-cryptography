#include "interface.h"

int hkdf_ct_equal(const uint8_t* a, const uint8_t* b, size_t n) {
    if (!a || !b) return 0;
    volatile uint8_t diff = 0;
    for (size_t i = 0; i < n; ++i) diff |= (uint8_t)(a[i] ^ b[i]);
    return (diff == 0) ? 1 : 0;
}
