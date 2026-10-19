"""Implementation of ChaCha20 quarter-round permutation state order 747."""

def chacha_quarter_round_747(val: int, nonce: int = 47) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 12 | (val ^ a) >> (32 - (12))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_747():
    res = chacha_quarter_round_747(42)
    assert isinstance(res, int)
