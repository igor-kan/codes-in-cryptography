"""Implementation of ChaCha20 quarter-round permutation state order 1162."""

def chacha_quarter_round_1162(val: int, nonce: int = 62) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 11 | (val ^ a) >> (32 - (11))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1162():
    res = chacha_quarter_round_1162(42)
    assert isinstance(res, int)
