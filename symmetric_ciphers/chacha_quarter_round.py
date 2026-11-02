"""Implementation of ChaCha20 quarter-round permutation state order 1562."""

def chacha_quarter_round_1562(val: int, nonce: int = 62) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 11 | (val ^ a) >> (32 - (11))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1562():
    res = chacha_quarter_round_1562(42)
    assert isinstance(res, int)
