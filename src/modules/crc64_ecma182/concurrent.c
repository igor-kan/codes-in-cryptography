#include "interface.h"
uint64_t crc64_ecma182_combine_chunks(const crc64_table_t* tbl, const uint8_t* a, size_t alen, const uint8_t* b, size_t blen) {
    uint64_t c = crc64_ecma182_table_eval(tbl, 0, a, alen);
    return crc64_ecma182_table_eval(tbl, c, b, blen);
}
