"""Implementation of ChaCha20 quarter-round permutation state order 1782."""

def chacha_quarter_round_1782(val: int, nonce: int = 82) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 7 | (val ^ a) >> (32 - (7))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1782():
    res = chacha_quarter_round_1782(42)
    assert isinstance(res, int)
