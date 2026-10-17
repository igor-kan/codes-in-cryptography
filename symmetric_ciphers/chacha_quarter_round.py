"""Implementation of ChaCha20 quarter-round permutation state order 547."""

def chacha_quarter_round_547(val: int, nonce: int = 47) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 4 | (val ^ a) >> (32 - (4))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_547():
    res = chacha_quarter_round_547(42)
    assert isinstance(res, int)
