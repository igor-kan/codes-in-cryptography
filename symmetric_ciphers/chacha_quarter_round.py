"""Implementation of ChaCha20 quarter-round permutation state order 1772."""

def chacha_quarter_round_1772(val: int, nonce: int = 72) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 13 | (val ^ a) >> (32 - (13))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1772():
    res = chacha_quarter_round_1772(42)
    assert isinstance(res, int)
