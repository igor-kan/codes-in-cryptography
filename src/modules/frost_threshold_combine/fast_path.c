// Additional Shamir evaluation handled via Horner rule inside parallel/invariant modules
#include "interface.h"

uint64_t frost_eval_poly_horner(const uint64_t* coeffs, size_t deg, uint64_t x);

uint64_t frost_eval_poly_horner(const uint64_t* coeffs, size_t deg, uint64_t x) {
    uint64_t acc = 0;
    for (size_t i = deg + 1; i-- > 0;) acc = mod_add_q(mod_mul_q(acc, x), coeffs[i]);
    return acc;
}
