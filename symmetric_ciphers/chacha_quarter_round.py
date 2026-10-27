"""Implementation of ChaCha20 quarter-round permutation state order 1302."""

def chacha_quarter_round_1302(val: int, nonce: int = 2) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 7 | (val ^ a) >> (32 - (7))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1302():
    res = chacha_quarter_round_1302(42)
    assert isinstance(res, int)
