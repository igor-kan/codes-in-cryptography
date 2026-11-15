# Ascon-128 Authenticated Encryption Permutation & Duplex AEAD (`ascon128_aead_perm`)

> Category: **Lightweight AEAD** | Language: **C11**

## Overview

Implements NIST SP 800-232 Ascon-p 320-bit sponge permutation (constant addition, 5-bit bitsliced S-box, linear diffusion layer) and authenticated encryption/decryption with 128-bit constant-time tag verification.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- decrypt(key, nonce, ad, encrypt(key, nonce, ad, pt)) recovers pt exactly.
- Single-bit flip in ciphertext, associated data, or tag triggers constant-time authentication failure.
- State registers are explicitly scrubbed on stack before returning.

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
