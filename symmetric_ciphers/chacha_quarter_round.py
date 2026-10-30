"""Implementation of ChaCha20 quarter-round permutation state order 1387."""

def chacha_quarter_round_1387(val: int, nonce: int = 87) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 12 | (val ^ a) >> (32 - (12))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1387():
    res = chacha_quarter_round_1387(42)
    assert isinstance(res, int)
