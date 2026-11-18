# Multiplicative Homomorphic ElGamal Encryption & Rerandomization (`elgamal_multiplicative_hom`)

> Category: **Homomorphic Cryptography** | Language: **C11**

## Overview

Implements ElGamal encryption over prime subgroup Z_p^* supporting componentwise ciphertext multiplication Dec(Enc(m1)*Enc(m2)) = m1*m2 mod p and rerandomization.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log P) modular exponentiation encrypt, decrypt, and ciphertext multiply` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Componentwise product of ciphertexts decrypts to exact modular product m1 * m2 mod p.
- Rerandomized ciphertext is unlinkable yet decrypts to identical plaintext.

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
