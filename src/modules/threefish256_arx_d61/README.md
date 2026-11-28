# Threefish-256 Tweakable 72-Round ARX Block Cipher (`threefish256_arx_d61`)

> Category: **Tweakable Block Ciphers** | Language: **C11**

## Overview

Implements the Threefish-256 tweakable block cipher with the C240 key parity word, 19 subkey injections, and a fully invertible MIX/permute network.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 72 MIX/permute rounds over four 64-bit words` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Decryption inverts encryption exactly for arbitrary keys and tweaks.

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
