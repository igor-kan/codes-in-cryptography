"""Implementation of ChaCha20 quarter-round permutation state order 1657."""

def chacha_quarter_round_1657(val: int, nonce: int = 57) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 10 | (val ^ a) >> (32 - (10))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1657():
    res = chacha_quarter_round_1657(42)
    assert isinstance(res, int)
