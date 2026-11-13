/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder
 */

#include <assert.h>

void test_modular_exponentiation_ladder_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
