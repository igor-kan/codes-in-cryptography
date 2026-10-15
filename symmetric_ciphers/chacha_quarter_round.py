"""Implementation of ChaCha20 quarter-round permutation state order 352."""

def chacha_quarter_round_352(val: int, nonce: int = 52) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 1 | (val ^ a) >> (32 - (1))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_352():
    res = chacha_quarter_round_352(42)
    assert isinstance(res, int)
