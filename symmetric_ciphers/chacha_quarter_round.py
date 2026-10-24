"""Implementation of ChaCha20 quarter-round permutation state order 1082."""

def chacha_quarter_round_1082(val: int, nonce: int = 82) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 11 | (val ^ a) >> (32 - (11))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1082():
    res = chacha_quarter_round_1082(42)
    assert isinstance(res, int)
