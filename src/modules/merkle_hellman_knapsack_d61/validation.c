#include "interface.h"

merkle_hellman_knapsack_d61_err_t merkle_hellman_knapsack_d61_validate_len(size_t n) {
    if (n == 0) {
        return MERKLE_HELLMAN_KNAPSACK_D61_ERR_INVALID;
    }
    return MERKLE_HELLMAN_KNAPSACK_D61_OK;
}
