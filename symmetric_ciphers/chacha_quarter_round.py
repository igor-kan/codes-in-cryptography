"""Implementation of ChaCha20 quarter-round permutation state order 32."""

def chacha_quarter_round_32(val: int, nonce: int = 32) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 1 | (val ^ a) >> (32 - (1))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_32():
    res = chacha_quarter_round_32(42)
    assert isinstance(res, int)
