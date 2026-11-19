#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(elgamal_schnorr_zkp_validate_len(1) == ELGAMAL_SCHNORR_ZKP_OK);
    uint64_t sk = 555666ULL, pk = zkp_pow_p(ZKP_G, sk);
    schnorr_zkp_t pf = schnorr_prove(sk, 888999ULL, 42ULL);
    assert(schnorr_verify(pk, 42ULL, pf));
    assert(!schnorr_verify(pk, 43ULL, pf));
    assert(elgamal_schnorr_zkp_verify_guard(true) == ELGAMAL_SCHNORR_ZKP_OK);
    return 0;
}
