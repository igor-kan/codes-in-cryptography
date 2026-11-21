# Shamir Secret Sharing Over Prime Field GF(257) (`shamir_lagrange_gf257_d56`)

> Category: **Threshold Cryptography** | Language: **C11**

## Overview

Evaluates degree-(k-1) threshold polynomials over prime field GF(257) and reconstructs the secret constant term from any k distinct shares via Fermat inversion.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(k^2) Lagrange interpolation at x=0` |
| **Space Complexity** | `O(k)` |

## Mathematical & Safety Invariants

- Any k-subset of n shares recovers the identical secret byte mod 257.

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
