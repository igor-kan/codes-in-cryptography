# Dual-Pass Nested IPAD/OPAD Keyed MAC (`hmac_xor_pad_mac_d56`)

> Category: **Message Authentication** | Language: **C11**

## Overview

Implements RFC-2104 nested outer/inner XOR key padding around a 64-bit compression core and constant-time tag comparison.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(B + |M|)` |
| **Space Complexity** | `O(B)` |

## Mathematical & Safety Invariants

- 1-bit perturbation in key or payload rejects verification cleanly.

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
