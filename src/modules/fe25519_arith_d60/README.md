# Curve25519 Prime Field GF(2^255 - 19) 5x51-Bit Multiplier (`fe25519_arith_d60`)

> Category: **Elliptic Curve Fields** | Language: **C11**

## Overview

Implements 51-bit radix-51 field addition, subtraction, and constant-time modular multiplication mod 2^255 - 19 without secret-dependent branches.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) constant-time 25-term schoolbook + 19*carry reduction` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Satisfies field commutativity a*b == b*a and multiplicative identity a*1 == a.

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
