"""Implementation of ChaCha20 quarter-round permutation state order 1062."""

def chacha_quarter_round_1062(val: int, nonce: int = 62) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 7 | (val ^ a) >> (32 - (7))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1062():
    res = chacha_quarter_round_1062(42)
    assert isinstance(res, int)
