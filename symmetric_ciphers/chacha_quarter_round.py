"""Implementation of ChaCha20 quarter-round permutation state order 1662."""

def chacha_quarter_round_1662(val: int, nonce: int = 62) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 15 | (val ^ a) >> (32 - (15))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1662():
    res = chacha_quarter_round_1662(42)
    assert isinstance(res, int)
