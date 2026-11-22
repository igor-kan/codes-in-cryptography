# Speck 64/128 Lightweight ARX Block Cipher (`speck64_128_arx_d57`)

> Category: **Lightweight Cryptography** | Language: **C11**

## Overview

Implements NSA Speck-64/128 27-round key-schedule expansion and invertibly pairs ARX encryption and decryption over 64-bit blocks.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 27-round ARX permutation` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Decryption strictly inverts 27-round ARX ciphertext back to plaintext.

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
