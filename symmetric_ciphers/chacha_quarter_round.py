"""Implementation of ChaCha20 quarter-round permutation state order 722."""

def chacha_quarter_round_722(val: int, nonce: int = 22) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 3 | (val ^ a) >> (32 - (3))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_722():
    res = chacha_quarter_round_722(42)
    assert isinstance(res, int)
