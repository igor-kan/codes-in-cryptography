#include "interface.h"
#include <assert.h>

int main(void) {
    const uint8_t check[9] = {'1','2','3','4','5','6','7','8','9'};
    uint64_t res = crc64_ecma182_bitwise(0, check, 9);
    assert(res == 0x6C40DF5F0B497347ULL);
    assert(crc64_ecma182_check_parity(check, 9) == CRC64_ECMA182_OK);
    return 0;
}
