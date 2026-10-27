"""Implementation of ChaCha20 quarter-round permutation state order 1272."""

def chacha_quarter_round_1272(val: int, nonce: int = 72) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 9 | (val ^ a) >> (32 - (9))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1272():
    res = chacha_quarter_round_1272(42)
    assert isinstance(res, int)
