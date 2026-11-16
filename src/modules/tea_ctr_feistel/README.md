# TEA 64-Round Feistel Network Block & CTR Stream Cipher (`tea_ctr_feistel`)

> Category: **Lightweight Block Ciphers** | Language: **C11**

## Overview

Implements Wheeler & Needham's Tiny Encryption Algorithm (TEA, delta=0x9E3779B9) forward/inverse 64-round Feistel cipher and big-endian 64-bit CTR mode keystream generator.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 32 cycles (64 rounds)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- decrypt(encrypt(v, key), key) == v across arbitrary 128-bit keys and 64-bit blocks.
- CTR stream encryption is an exact involution: ctr_xor(ctr_xor(msg)) == msg.

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
