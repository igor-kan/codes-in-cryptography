# RC4-Drop3072 Hardened KSA Permutation Stream Cipher (`rc4_drop3072_stream_c11`)

> Category: **Stream Ciphers** | Language: **C11**

## Overview

Implements the RC4 stream key-scheduling permutation with an initial 3072-byte keystream discard to mitigate Fluhrer-Mantin-Shamir key-byte statistical biases.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(256 + 3072 + L) state shuffle with initial bias-drop discard` |
| **Space Complexity** | `O(256) byte permutation S-array` |

## Mathematical & Safety Invariants

- Keystream permutation preserves all 256 distinct byte values and XOR decryption is involutive.

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
