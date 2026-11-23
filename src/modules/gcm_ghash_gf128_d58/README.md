# GF(2^64) Binary Carryless Polynomial Fold (GHASH-64) (`gcm_ghash_gf128_d58`)

> Category: **Universal Polynomial Hash** | Language: **C11**

## Overview

Computes carryless binary polynomial multiplications in GF(2^64) modulo x^64 + x^4 + x^3 + x + 1 cleanly without lookup tables.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(64 * N) branchless reduction` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Polynomial field multiplication satisfies commutativity a * b == b * a and distributivity cleanly.

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
