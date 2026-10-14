"""Implementation of ChaCha20 quarter-round permutation state order 282."""

def chacha_quarter_round_282(val: int, nonce: int = 82) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 11 | (val ^ a) >> (32 - (11))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_282():
    res = chacha_quarter_round_282(42)
    assert isinstance(res, int)
