#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(elgamal_multiplicative_hom_validate_len(1) == ELGAMAL_MULTIPLICATIVE_HOM_OK);
    uint64_t sk = 12345ULL, pk = elg_pow(ELG_G, sk);
    elg_cipher_t e1 = elg_encrypt(pk, 42ULL, 101ULL);
    elg_cipher_t e2 = elg_encrypt(pk, 10ULL, 202ULL);
    elg_cipher_t prod = elg_hom_mul(e1, e2);
    assert(elg_decrypt(sk, prod) == 420ULL);
    assert(elgamal_multiplicative_hom_verify_guard(true) == ELGAMAL_MULTIPLICATIVE_HOM_OK);
    return 0;
}
