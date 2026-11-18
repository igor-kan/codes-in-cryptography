#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(solovay_strassen_jacobi_validate_len(1) == SOLOVAY_STRASSEN_JACOBI_OK);
    assert(jacobi_symbol(1001, 9907) == -1);
    assert(solovay_strassen_prime(1000003ULL));
    assert(!solovay_strassen_prime(561ULL)); /* Carmichael number 561 */
    assert(solovay_strassen_jacobi_verify_guard(true) == SOLOVAY_STRASSEN_JACOBI_OK);
    return 0;
}
