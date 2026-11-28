# Merkle-Hellman Superincreasing Knapsack Cryptosystem (`merkle_hellman_knapsack_d61`)

> Category: **Knapsack Cryptography** | Language: **C11**

## Overview

Encrypts 8-bit messages as the subset sum of a modularly-masked superincreasing knapsack sequence and decrypts greedily after restoring the trapdoor factor.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(B) subset-sum encode and greedy superincreasing decode` |
| **Space Complexity** | `O(B) public key vector` |

## Mathematical & Safety Invariants

- Every 8-bit message round-trips through encrypt then decrypt exactly.

## Module Architecture

| File | Lifecycle Role |
| :--- | :--- |
| `types.h` | Stage 01 |
| `errors.h` | Stage 02 |
| `interface.h` | Stage 03 |
| `core.c` | Stage 04 |
| `validation.c` | Stage 05 |
| `fast_path.c` | Stage 06 |
| `concurrent.c` | Stage 07 |
| `invariants.c` | Stage 08 |
| `unit_tests.c` | Stage 09 |
| `property_tests.c` | Stage 10 |
| `benchmark.c` | Stage 11 |
| `README.md` | Stage 12 |

## Verification & Execution Example

```text
gcc -std=c11 -O2 -Wall -Wextra -Werror -pthread core.c validation.c fast_path.c concurrent.c invariants.c unit_tests.c -lm -o test_bin && ./test_bin
```

---
© 2026 Igor Kan
