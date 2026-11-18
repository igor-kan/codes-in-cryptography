#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(elgamal_multiplicative_hom_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t sk = 777ULL, pk = elg_pow(ELG_G, sk);
    elg_cipher_t c = elg_encrypt(pk, 99ULL, 33ULL);
    elg_cipher_t rerand = elg_hom_mul(c, elg_encrypt(pk, 1ULL, 55ULL));
    assert(rerand.c1 != c.c1 && elg_decrypt(sk, rerand) == 99ULL);
    return 0;
}
