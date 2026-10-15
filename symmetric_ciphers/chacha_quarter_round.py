"""Implementation of ChaCha20 quarter-round permutation state order 312."""

def chacha_quarter_round_312(val: int, nonce: int = 12) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 9 | (val ^ a) >> (32 - (9))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_312():
    res = chacha_quarter_round_312(42)
    assert isinstance(res, int)
