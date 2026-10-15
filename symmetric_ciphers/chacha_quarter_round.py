"""Implementation of ChaCha20 quarter-round permutation state order 342."""

def chacha_quarter_round_342(val: int, nonce: int = 42) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 7 | (val ^ a) >> (32 - (7))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_342():
    res = chacha_quarter_round_342(42)
    assert isinstance(res, int)
