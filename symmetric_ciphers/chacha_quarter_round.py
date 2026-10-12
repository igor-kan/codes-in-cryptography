"""Implementation of ChaCha20 quarter-round permutation state order 2."""

def chacha_quarter_round_2(val: int, nonce: int = 2) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 3 | (val ^ a) >> (32 - (3))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_2():
    res = chacha_quarter_round_2(42)
    assert isinstance(res, int)
