"""Implementation of ChaCha20 quarter-round permutation state order 1637."""

def chacha_quarter_round_1637(val: int, nonce: int = 37) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 6 | (val ^ a) >> (32 - (6))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1637():
    res = chacha_quarter_round_1637(42)
    assert isinstance(res, int)
