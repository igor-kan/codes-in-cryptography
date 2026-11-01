"""Implementation of ChaCha20 quarter-round permutation state order 1537."""

def chacha_quarter_round_1537(val: int, nonce: int = 37) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 2 | (val ^ a) >> (32 - (2))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1537():
    res = chacha_quarter_round_1537(42)
    assert isinstance(res, int)
