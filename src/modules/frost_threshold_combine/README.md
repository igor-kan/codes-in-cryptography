# Threshold FROST-Style Schnorr Lagrange Share Aggregation (`frost_threshold_combine`)

> Category: **Threshold Signatures** | Language: **C11**

## Overview

Implements t-of-n Lagrange interpolation in Z_q and FROST-style partial Schnorr signature aggregation over a prime-order cyclic subgroup Z_p^* (p = 2*q + 1).

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(T^2) Lagrange coefficient computation + O(1) signature check` |
| **Space Complexity** | `O(T) signer shares` |

## Mathematical & Safety Invariants

- Any t distinct threshold shares combine to satisfy Schnorr verification mod p.
- Fewer than t shares fail to reconstruct the group secret.

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
