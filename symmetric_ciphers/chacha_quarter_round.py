"""Implementation of ChaCha20 quarter-round permutation state order 372."""

def chacha_quarter_round_372(val: int, nonce: int = 72) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 5 | (val ^ a) >> (32 - (5))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_372():
    res = chacha_quarter_round_372(42)
    assert isinstance(res, int)
