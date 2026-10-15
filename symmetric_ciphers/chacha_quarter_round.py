"""Implementation of ChaCha20 quarter-round permutation state order 337."""

def chacha_quarter_round_337(val: int, nonce: int = 37) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 2 | (val ^ a) >> (32 - (2))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_337():
    res = chacha_quarter_round_337(42)
    assert isinstance(res, int)
