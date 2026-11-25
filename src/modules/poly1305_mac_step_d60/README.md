# Poly1305 26-Bit 5-Limb GF(2^130 - 5) One-Time Authenticator (`poly1305_mac_step_d60`)

> Category: **Message Authentication** | Language: **C11**

## Overview

Implements RFC 8439 Poly1305 clamping, 5x26-bit limb representation, carry propagation mod 2^130 - 5, and final tag addition.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(B) 16-byte block Horner accumulation mod 2^130 - 5` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Matches exact algebraic Horner polynomial mod 2^130 - 5.

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
