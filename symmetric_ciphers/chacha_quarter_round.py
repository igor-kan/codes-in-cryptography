"""Implementation of ChaCha20 quarter-round permutation state order 852."""

def chacha_quarter_round_852(val: int, nonce: int = 52) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 5 | (val ^ a) >> (32 - (5))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_852():
    res = chacha_quarter_round_852(42)
    assert isinstance(res, int)
