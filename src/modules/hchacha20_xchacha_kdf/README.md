# HChaCha20 Extended-Nonce Subkey Derivation (draft-irtf-cfrg-xchacha) (`hchacha20_xchacha_kdf`)

> Category: **Key Derivation & Stream Ciphers** | Language: **C11**

## Overview

Implements RFC/IRTF HChaCha20 converting a 256-bit key and 128-bit prefix nonce into a 256-bit subkey without final state addition, matching official IRTF XChaCha test vectors.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 20-round quarter-round matrix permutation` |
| **Space Complexity** | `64-byte state matrix` |

## Mathematical & Safety Invariants

- Matches RFC/IRTF HChaCha20 reference subkey vector byte-for-byte.
- Single-bit change in 16-byte nonce alters the 32-byte derived subkey.

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
