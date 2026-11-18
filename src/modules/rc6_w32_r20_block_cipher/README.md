# RC6-32/20/16 Data-Dependent Rotation Symmetric Block Cipher (`rc6_w32_r20_block_cipher`)

> Category: **Block Ciphers** | Language: **C11**

## Overview

Implements Rivest's RC6-32/20/16 128-bit block cipher with four 32-bit working registers and quadratic data-dependent rotations.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(R) quadratic f(x) = x*(2x+1) mod 2^32 data-dependent rounds` |
| **Space Complexity** | `O(R) 44-word expanded subkey schedule` |

## Mathematical & Safety Invariants

- Decryption is the exact inverse of encryption for all 128-bit blocks and keys.

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
