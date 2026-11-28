#ifndef MERKLE_HELLMAN_KNAPSACK_D61_ERRORS_H
#define MERKLE_HELLMAN_KNAPSACK_D61_ERRORS_H

typedef enum merkle_hellman_knapsack_d61_err {
    MERKLE_HELLMAN_KNAPSACK_D61_OK = 0,
    MERKLE_HELLMAN_KNAPSACK_D61_ERR_NULL = -1,
    MERKLE_HELLMAN_KNAPSACK_D61_ERR_BOUNDS = -2,
    MERKLE_HELLMAN_KNAPSACK_D61_ERR_INVALID = -3,
    MERKLE_HELLMAN_KNAPSACK_D61_ERR_OVERFLOW = -4,
    MERKLE_HELLMAN_KNAPSACK_D61_ERR_INVARIANT = -5
} merkle_hellman_knapsack_d61_err_t;



static inline const char* merkle_hellman_knapsack_d61_err_str(merkle_hellman_knapsack_d61_err_t err) {
    switch (err) {
        case MERKLE_HELLMAN_KNAPSACK_D61_OK: return "ok";
        case MERKLE_HELLMAN_KNAPSACK_D61_ERR_NULL: return "null pointer supplied";
        case MERKLE_HELLMAN_KNAPSACK_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case MERKLE_HELLMAN_KNAPSACK_D61_ERR_INVALID: return "domain precondition violated";
        case MERKLE_HELLMAN_KNAPSACK_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case MERKLE_HELLMAN_KNAPSACK_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* MERKLE_HELLMAN_KNAPSACK_D61_ERRORS_H */
