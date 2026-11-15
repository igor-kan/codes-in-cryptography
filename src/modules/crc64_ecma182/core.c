#include "interface.h"

uint64_t crc64_ecma182_bitwise(uint64_t crc, const uint8_t* data, size_t len) {
    if (!data && len > 0) return crc;
    for (size_t i = 0; i < len; ++i) {
        crc ^= ((uint64_t)data[i] << 56);
        for (int b = 0; b < 8; ++b) {
            uint64_t mask = (uint64_t)(-(int64_t)(crc >> 63));
            crc = (crc << 1) ^ (CRC64_ECMA_POLY & mask);
        }
    }
    return crc;
}
