#include "interface.h"
crc64_ecma182_err_t crc64_ecma182_validate(const uint8_t* data, size_t len) {
    return (len > 0 && !data) ? CRC64_ECMA182_ERR_NULL : CRC64_ECMA182_OK;
}
