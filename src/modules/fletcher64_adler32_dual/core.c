#include "interface.h"
#include <math.h>
#include <string.h>

uint32_t compute_adler32(const uint8_t* buf, size_t len) {
    uint32_t a = 1, b = 0;
    for (size_t i = 0; i < len; ++i) {
        a = (a + buf[i]) % 65521U;
        b = (b + a) % 65521U;
    }
    return (b << 16) | a;
}
uint64_t compute_fletcher64(const uint32_t* words, size_t count) {
    uint64_t sum1 = 0, sum2 = 0;
    for (size_t i = 0; i < count; ++i) {
        sum1 = (sum1 + words[i]) % 4294967295ULL;
        sum2 = (sum2 + sum1) % 4294967295ULL;
    }
    return (sum2 << 32) | sum1;
}
