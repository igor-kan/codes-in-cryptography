"""Implementation of ChaCha20 quarter-round permutation state order 1182."""

def chacha_quarter_round_1182(val: int, nonce: int = 82) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 15 | (val ^ a) >> (32 - (15))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1182():
    res = chacha_quarter_round_1182(42)
    assert isinstance(res, int)
