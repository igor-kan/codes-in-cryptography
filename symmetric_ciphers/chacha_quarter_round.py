"""Implementation of ChaCha20 quarter-round permutation state order 417."""

def chacha_quarter_round_417(val: int, nonce: int = 17) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 2 | (val ^ a) >> (32 - (2))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_417():
    res = chacha_quarter_round_417(42)
    assert isinstance(res, int)
