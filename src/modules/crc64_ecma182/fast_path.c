#include "interface.h"

void crc64_ecma182_init_table(crc64_table_t* tbl) {
    for (uint64_t i = 0; i < 256; ++i) {
        uint64_t c = i << 56;
        for (int b = 0; b < 8; ++b) {
            c = (c & (1ULL << 63)) ? ((c << 1) ^ CRC64_ECMA_POLY) : (c << 1);
        }
        tbl->t[i] = c;
    }
}

uint64_t crc64_ecma182_table_eval(const crc64_table_t* tbl, uint64_t crc, const uint8_t* data, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        uint8_t idx = (uint8_t)((crc >> 56) ^ data[i]);
        crc = tbl->t[idx] ^ (crc << 8);
    }
    return crc;
}
