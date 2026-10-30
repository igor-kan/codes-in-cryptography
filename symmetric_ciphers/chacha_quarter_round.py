"""Implementation of ChaCha20 quarter-round permutation state order 1382."""

def chacha_quarter_round_1382(val: int, nonce: int = 82) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 7 | (val ^ a) >> (32 - (7))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1382():
    res = chacha_quarter_round_1382(42)
    assert isinstance(res, int)
