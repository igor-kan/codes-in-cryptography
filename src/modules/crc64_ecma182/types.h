#ifndef CRC64_ECMA182_TYPES_H
#define CRC64_ECMA182_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define CRC64_ECMA_POLY 0x42F0E1EBA9EA3693ULL
typedef struct {
    uint64_t t[256];
} crc64_table_t;

#endif /* CRC64_ECMA182_TYPES_H */
