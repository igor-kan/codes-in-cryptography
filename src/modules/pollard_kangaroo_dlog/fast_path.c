#include "interface.h"

uint64_t fast_jump_step(uint64_t x, const uint64_t jumps[32]) {
    return jumps[x & 31ULL];
}
