#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint32_t B1[32] = {1}, B2[32] = {1}, V1[8 * 32], V2[8 * 32];
    scrypt_parallel_romix(B1, V1, B2, V2, 1, 8);
    assert(memcmp(B1, B2, sizeof(B1)) == 0);
    return 0;
}
