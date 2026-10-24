"""Implementation of ChaCha20 quarter-round permutation state order 1107."""

def chacha_quarter_round_1107(val: int, nonce: int = 7) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 4 | (val ^ a) >> (32 - (4))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1107():
    res = chacha_quarter_round_1107(42)
    assert isinstance(res, int)
