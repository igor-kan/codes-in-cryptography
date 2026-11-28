#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(paillier_additive_he_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    assert(paillier_additive_check_d61(1000ULL, 2000ULL, 5ULL, 9ULL));
    assert(paillier_additive_check_d61(0ULL, 17ULL, 3ULL, 11ULL));
    uint64_t c1 = paillier_encrypt_d61(19ULL, 13ULL);
    uint64_t c2 = paillier_encrypt_d61(23ULL, 17ULL);
    uint64_t n2 = PAIL_N * PAIL_N;
    uint64_t prod = (uint64_t)(((__uint128_t)c1 * c2) % n2);
    assert(paillier_decrypt_d61(prod) == 42ULL);
    assert(paillier_decrypt_d61(c1) != 23ULL);
    return 0;
}
