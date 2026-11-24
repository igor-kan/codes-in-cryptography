#include "interface.h"
#include <math.h>
#include <string.h>

uint32_t galois32_step(uint32_t *st) {
    if (*st == 0u) *st = 1u;
    uint32_t lsb = *st & 1u;
    *st >>= 1;
    if (lsb) *st ^= 0xD0000001u;
    return lsb;
}
