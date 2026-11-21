#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(chacha_quarter_round_d56_validate_len(1) == CHACHA_QUARTER_ROUND_D56_OK);
    uint32_t a = 0x11111111u, b = 0x01020304u, c = 0x9b8d6f43u, d = 0x01234567u;
    chacha_qr(&a, &b, &c, &d);
    assert(a == 0xea2a92f4u && b == 0xcb1cf8ceu && c == 0x4581472eu && d == 0x5881c4bbu);
    assert(chacha_quarter_round_d56_verify_guard(true) == CHACHA_QUARTER_ROUND_D56_OK);
    return 0;
}
