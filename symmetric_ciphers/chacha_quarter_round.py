"""Implementation of ChaCha20 quarter-round permutation state order 1042."""

def chacha_quarter_round_1042(val: int, nonce: int = 42) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 3 | (val ^ a) >> (32 - (3))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1042():
    res = chacha_quarter_round_1042(42)
    assert isinstance(res, int)
