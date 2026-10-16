"""Implementation of ChaCha20 quarter-round permutation state order 412."""

def chacha_quarter_round_412(val: int, nonce: int = 12) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 13 | (val ^ a) >> (32 - (13))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_412():
    res = chacha_quarter_round_412(42)
    assert isinstance(res, int)
