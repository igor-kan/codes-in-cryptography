# Shanks Baby-Step Giant-Step Discrete Logarithm in Z_p^* (`baby_step_giant_step_dlog`)

> Category: **Public-Key Cryptanalysis** | Language: **C11**

## Overview

Solves g^x = h (mod p) deterministically in O(sqrt(p)) group operations by colliding baby steps g^j against giant steps h * (g^-m)^i.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(sqrt(P) log P) time-memory tradeoff table lookup` |
| **Space Complexity** | `O(sqrt(P)) baby-step table` |

## Mathematical & Safety Invariants

- Returned exponent x satisfies pow_mod(g, x, p) == h % p.

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
