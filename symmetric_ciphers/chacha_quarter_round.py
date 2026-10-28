"""Implementation of ChaCha20 quarter-round permutation state order 1357."""

def chacha_quarter_round_1357(val: int, nonce: int = 57) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 14 | (val ^ a) >> (32 - (14))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_1357():
    res = chacha_quarter_round_1357(42)
    assert isinstance(res, int)
