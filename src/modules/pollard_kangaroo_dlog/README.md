# Pollard Lambda / Kangaroo Discrete Logarithm Solver (`pollard_kangaroo_dlog`)

> Category: **Number-Theoretic Cryptanalysis** | Language: **C11**

## Overview

Implements Pollard's Kangaroo (lambda) algorithm solving g^x == h (mod p) for bounded secret exponents using distinguished pseudo-random jump steps with wild/tame collision trapping.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(sqrt(W)) group operations on bounded interval width W` |
| **Space Complexity** | `O(1) memory pseudo-random walk` |

## Mathematical & Safety Invariants

- Recovered exponent x strictly obeys pow_mod(g, x, p) == h mod p.

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
