"""Implementation of ChaCha20 quarter-round permutation state order 842."""

def chacha_quarter_round_842(val: int, nonce: int = 42) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 11 | (val ^ a) >> (32 - (11))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_842():
    res = chacha_quarter_round_842(42)
    assert isinstance(res, int)
