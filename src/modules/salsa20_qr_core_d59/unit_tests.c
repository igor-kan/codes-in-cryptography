#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(salsa20_qr_core_d59_validate_len(1) == SALSA20_QR_CORE_D59_OK);
    uint32_t y0 = 0x00000001u, y1 = 0, y2 = 0, y3 = 0;
    salsa_qr(&y0, &y1, &y2, &y3);
    assert(y0 == 0x08008145u && y1 == 0x00000080u && y2 == 0x00010200u && y3 == 0x20500000u);
    assert(salsa20_qr_core_d59_verify_guard(true) == SALSA20_QR_CORE_D59_OK);
    return 0;
}
