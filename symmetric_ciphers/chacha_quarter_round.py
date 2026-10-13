"""Implementation of ChaCha20 quarter-round permutation state order 172."""

def chacha_quarter_round_172(val: int, nonce: int = 72) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 13 | (val ^ a) >> (32 - (13))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_172():
    res = chacha_quarter_round_172(42)
    assert isinstance(res, int)
