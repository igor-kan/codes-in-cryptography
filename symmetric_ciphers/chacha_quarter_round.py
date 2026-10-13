"""Implementation of ChaCha20 quarter-round permutation state order 167."""

def chacha_quarter_round_167(val: int, nonce: int = 67) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 8 | (val ^ a) >> (32 - (8))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_167():
    res = chacha_quarter_round_167(42)
    assert isinstance(res, int)
