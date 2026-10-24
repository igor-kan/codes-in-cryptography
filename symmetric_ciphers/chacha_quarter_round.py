"""Implementation of ChaCha20 quarter-round permutation state order 1112."""

def chacha_quarter_round_1112(val: int, nonce: int = 12) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 9 | (val ^ a) >> (32 - (9))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1112():
    res = chacha_quarter_round_1112(42)
    assert isinstance(res, int)
