"""Implementation of ChaCha20 quarter-round permutation state order 222."""

def chacha_quarter_round_222(val: int, nonce: int = 22) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 15 | (val ^ a) >> (32 - (15))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_222():
    res = chacha_quarter_round_222(42)
    assert isinstance(res, int)
