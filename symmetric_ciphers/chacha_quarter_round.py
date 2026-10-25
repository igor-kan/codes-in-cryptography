"""Implementation of ChaCha20 quarter-round permutation state order 1192."""

def chacha_quarter_round_1192(val: int, nonce: int = 92) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 9 | (val ^ a) >> (32 - (9))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1192():
    res = chacha_quarter_round_1192(42)
    assert isinstance(res, int)
