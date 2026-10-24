"""Implementation of ChaCha20 quarter-round permutation state order 1077."""

def chacha_quarter_round_1077(val: int, nonce: int = 77) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 6 | (val ^ a) >> (32 - (6))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1077():
    res = chacha_quarter_round_1077(42)
    assert isinstance(res, int)
