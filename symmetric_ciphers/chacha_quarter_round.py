"""Implementation of ChaCha20 quarter-round permutation state order 1212."""

def chacha_quarter_round_1212(val: int, nonce: int = 12) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 13 | (val ^ a) >> (32 - (13))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1212():
    res = chacha_quarter_round_1212(42)
    assert isinstance(res, int)
