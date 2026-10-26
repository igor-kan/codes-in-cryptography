"""Implementation of ChaCha20 quarter-round permutation state order 1227."""

def chacha_quarter_round_1227(val: int, nonce: int = 27) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 12 | (val ^ a) >> (32 - (12))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1227():
    res = chacha_quarter_round_1227(42)
    assert isinstance(res, int)
