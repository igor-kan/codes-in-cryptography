#include "interface.h"

merkle_hellman_knapsack_d61_err_t merkle_hellman_knapsack_d61_verify_guard(bool cond) {
    if (!cond) {
        return MERKLE_HELLMAN_KNAPSACK_D61_ERR_INVARIANT;
    }
    return MERKLE_HELLMAN_KNAPSACK_D61_OK;
}
