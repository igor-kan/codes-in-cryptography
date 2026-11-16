#include "interface.h"
#include <assert.h>

int main(void) {
    tea_key_t key = {{0xA5A5A5A5U, 0x5A5A5A5AU, 0x13579BDFU, 0x2468ACE0U}};
    assert(tea_batch_roundtrip_mt(&key, 400, 4) == TEA_CTR_FEISTEL_OK);
    return 0;
}
