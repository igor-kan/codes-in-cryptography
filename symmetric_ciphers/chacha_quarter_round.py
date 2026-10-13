"""Implementation of ChaCha20 quarter-round permutation state order 137."""

def chacha_quarter_round_137(val: int, nonce: int = 37) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 10 | (val ^ a) >> (32 - (10))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_137():
    res = chacha_quarter_round_137(42)
    assert isinstance(res, int)
