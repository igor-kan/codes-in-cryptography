#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t buf[256];
    for (int i = 0; i < 256; ++i) buf[i] = (uint8_t)(i * 19 + 5);
    assert(crc64_ecma182_check_parity(buf, 256) == CRC64_ECMA182_OK);
    // Streaming linearity test: crc(A || B) == crc(crc(0, A), B)
    crc64_table_t tbl; crc64_ecma182_init_table(&tbl);
    uint64_t full = crc64_ecma182_table_eval(&tbl, 0, buf, 256);
    uint64_t half = crc64_ecma182_table_eval(&tbl, 0, buf, 100);
    uint64_t split = crc64_ecma182_table_eval(&tbl, half, buf + 100, 156);
    assert(full == split);
    return 0;
}
