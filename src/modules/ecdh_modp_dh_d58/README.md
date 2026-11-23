# Safe-Prime Diffie-Hellman Shared Key Agreement (`ecdh_modp_dh_d58`)

> Category: **Key Exchange** | Language: **C11**

## Overview

Computes Diffie-Hellman public shares g^a mod p and verifies Alice and Bob derive the identical shared secret (g^b)^a == (g^a)^b mod p.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log P) square-and-multiply` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Alice and Bob secret derivations converge identically for arbitrary exponents.

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
