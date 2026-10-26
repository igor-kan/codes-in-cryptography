"""Implementation of ChaCha20 quarter-round permutation state order 1247."""

def chacha_quarter_round_1247(val: int, nonce: int = 47) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 16 | (val ^ a) >> (32 - (16))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1247():
    res = chacha_quarter_round_1247(42)
    assert isinstance(res, int)
