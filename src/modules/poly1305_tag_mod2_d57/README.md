# Mersenne-61 Carter-Wegman Polynomial Authenticator (`poly1305_tag_mod2_d57`)

> Category: **Universal Hashing** | Language: **C11**

## Overview

Evaluates Carter-Wegman one-time universal tags modulo prime M61 = 2^61 - 1 with 128-bit modular reduction and additive secret mask.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Distinct messages over fixed key/nonce satisfy epsilon-delta universality.

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
