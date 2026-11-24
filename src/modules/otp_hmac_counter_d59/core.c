#include "interface.h"
#include <math.h>
#include <string.h>

uint32_t hotp6_generate(uint64_t key, uint64_t counter) {
    uint64_t h = (key ^ 0x5A5A5A5A5A5A5A5AULL) + counter * 0x9E3779B97F4A7C15ULL;
    for (int r = 0; r < 6; ++r) {
        h ^= h >> 27;
        h *= 0xBF58476D1CE4E5B9ULL;
        h ^= key + (uint64_t)r;
    }
    uint32_t offset = (uint32_t)(h & 3ULL) * 8u;
    uint32_t bin = (uint32_t)((h >> offset) & 0x7FFFFFFFu);
    return bin % 1000000u;
}
