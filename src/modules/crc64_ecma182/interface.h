#ifndef CRC64_ECMA182_INTERFACE_H
#define CRC64_ECMA182_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t crc64_ecma182_bitwise(uint64_t crc, const uint8_t* data, size_t len);
void crc64_ecma182_init_table(crc64_table_t* tbl);
uint64_t crc64_ecma182_table_eval(const crc64_table_t* tbl, uint64_t crc, const uint8_t* data, size_t len);
crc64_ecma182_err_t crc64_ecma182_validate(const uint8_t* data, size_t len);
crc64_ecma182_err_t crc64_ecma182_check_parity(const uint8_t* data, size_t len);

#endif /* CRC64_ECMA182_INTERFACE_H */
