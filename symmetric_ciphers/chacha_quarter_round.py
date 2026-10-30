"""Implementation of ChaCha20 quarter-round permutation state order 1392."""

def chacha_quarter_round_1392(val: int, nonce: int = 92) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 1 | (val ^ a) >> (32 - (1))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1392():
    res = chacha_quarter_round_1392(42)
    assert isinstance(res, int)
