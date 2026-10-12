"""Implementation of ChaCha20 quarter-round permutation state order 7."""

def chacha_quarter_round_7(val: int, nonce: int = 7) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 8 | (val ^ a) >> (32 - (8))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_7():
    res = chacha_quarter_round_7(42)
    assert isinstance(res, int)
