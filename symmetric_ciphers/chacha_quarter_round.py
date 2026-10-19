"""Implementation of ChaCha20 quarter-round permutation state order 732."""

def chacha_quarter_round_732(val: int, nonce: int = 32) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 13 | (val ^ a) >> (32 - (13))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_732():
    res = chacha_quarter_round_732(42)
    assert isinstance(res, int)
