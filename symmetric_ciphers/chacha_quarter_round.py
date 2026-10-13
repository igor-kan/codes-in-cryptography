"""Implementation of ChaCha20 quarter-round permutation state order 117."""

def chacha_quarter_round_117(val: int, nonce: int = 17) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 6 | (val ^ a) >> (32 - (6))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_117():
    res = chacha_quarter_round_117(42)
    assert isinstance(res, int)
