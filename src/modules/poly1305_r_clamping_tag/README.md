# RFC 8439 Poly1305 Key Clamping & Multi-Limb Polynomial Evaluation (`poly1305_r_clamping_tag`)

> Category: **Message Authentication** | Language: **C11**

## Overview

Applies RFC 8439 bit-clamping mask to 128-bit evaluation key r and accumulates message chunks modulo 2^130 - 5 using 128-bit integer arithmetic.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(L) 16-byte block Horner polynomial evaluation mod 2^130 - 5` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Clamped r has top 4 bits of bytes 3, 7, 11, 15 and bottom 2 bits of bytes 4, 8, 12 cleared.

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
