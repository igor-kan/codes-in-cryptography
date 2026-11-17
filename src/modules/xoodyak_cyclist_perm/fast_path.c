#include "interface.h"

void xoodoo_fast_xor_in(xoodoo_state_t* st, const uint8_t* block, size_t len) {
    uint8_t* bytes = (uint8_t*)st->lanes;
    for (size_t i = 0; i < len && i < 48; ++i) bytes[i] ^= block[i];
}
