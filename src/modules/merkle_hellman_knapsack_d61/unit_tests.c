#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(merkle_hellman_knapsack_d61_validate_len(1) == MERKLE_HELLMAN_KNAPSACK_D61_OK);
    mh_key_d61_t k;
    mh_public_key_d61(&k);
    assert(mh_encrypt_d61(&k, 0U) == 0ULL);
    uint64_t c = mh_encrypt_d61(&k, 0xB3U);
    assert(c == 1297ULL);
    assert(mh_decrypt_d61(&k, c) == 0xB3U);
    assert(merkle_hellman_knapsack_d61_verify_guard(true) == MERKLE_HELLMAN_KNAPSACK_D61_OK);
    return 0;
}
