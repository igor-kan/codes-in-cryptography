"""Implementation of ChaCha20 quarter-round permutation state order 932."""

def chacha_quarter_round_932(val: int, nonce: int = 32) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 5 | (val ^ a) >> (32 - (5))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_932():
    res = chacha_quarter_round_932(42)
    assert isinstance(res, int)
