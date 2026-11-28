# Trivium 288-Bit Coupled Shift-Register Keystream Generator (`trivium_lfsr_stream_d61`)

> Category: **Stream Ciphers** | Language: **C11**

## Overview

Implements the Trivium stream cipher with three coupled feedback registers, quadratic AND taps, and a 4x288 initialization warm-up.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) per output bit after 1152-clock key/IV warm-up` |
| **Space Complexity** | `O(1) 288-bit state` |

## Mathematical & Safety Invariants

- Equal key/IV pairs reproduce identical keystream while distinct IVs diverge.

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
