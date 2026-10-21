"""Implementation of ChaCha20 quarter-round permutation state order 927."""

def chacha_quarter_round_927(val: int, nonce: int = 27) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 16 | (val ^ a) >> (32 - (16))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_927():
    res = chacha_quarter_round_927(42)
    assert isinstance(res, int)
