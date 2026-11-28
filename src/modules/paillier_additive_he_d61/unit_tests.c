#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(paillier_additive_he_d61_validate_len(1) == PAILLIER_ADDITIVE_HE_D61_OK);
    paillier_key_d61_t k;
    paillier_keygen_d61(&k);
    uint64_t c = paillier_encrypt_d61(42ULL, 7ULL);
    assert(c != 0ULL);
    assert(paillier_decrypt_d61(c) == 42ULL);
    assert(c != paillier_encrypt_d61(43ULL, 7ULL));
    assert(paillier_additive_he_d61_verify_guard(true) == PAILLIER_ADDITIVE_HE_D61_OK);
    return 0;
}
