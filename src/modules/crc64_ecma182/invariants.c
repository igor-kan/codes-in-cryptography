#include "interface.h"

crc64_ecma182_err_t crc64_ecma182_check_parity(const uint8_t* data, size_t len) {
    crc64_table_t tbl;
    crc64_ecma182_init_table(&tbl);
    uint64_t bw = crc64_ecma182_bitwise(0, data, len);
    uint64_t tb = crc64_ecma182_table_eval(&tbl, 0, data, len);
    return (bw == tb) ? CRC64_ECMA182_OK : CRC64_ECMA182_ERR_INVARIANT;
}
