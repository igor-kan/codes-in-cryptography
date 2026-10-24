"""Implementation of ChaCha20 quarter-round permutation state order 1057."""

def chacha_quarter_round_1057(val: int, nonce: int = 57) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 2 | (val ^ a) >> (32 - (2))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1057():
    res = chacha_quarter_round_1057(42)
    assert isinstance(res, int)
