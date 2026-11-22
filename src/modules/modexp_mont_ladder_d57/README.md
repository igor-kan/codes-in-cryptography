# Fixed-Schedule Montgomery Powering Ladder (`modexp_mont_ladder_d57`)

> Category: **Asymmetric Arithmetic** | Language: **C11**

## Overview

Computes (base^exp) mod m via a constant-trace 64-step Montgomery ladder performing identical multiply-and-square work per exponent bit.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(64) modular squarings and multiplies` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Ladder matches Fermat theorem a^(p-1) mod p == 1 cleanly.

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
