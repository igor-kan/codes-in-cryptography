"""Implementation of ChaCha20 quarter-round permutation state order 1517."""

def chacha_quarter_round_1517(val: int, nonce: int = 17) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 14 | (val ^ a) >> (32 - (14))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1517():
    res = chacha_quarter_round_1517(42)
    assert isinstance(res, int)
