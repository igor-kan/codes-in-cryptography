#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(lfsr_galois32_d59_validate_len(1) == LFSR_GALOIS32_D59_OK);
    uint32_t st = 0xACE1u;
    for (int i = 0; i < 200; ++i) {
        (void)galois32_step(&st);
        assert(st != 0u);
    }
    assert(st != 0xACE1u);
    assert(lfsr_galois32_d59_verify_guard(true) == LFSR_GALOIS32_D59_OK);
    return 0;
}
