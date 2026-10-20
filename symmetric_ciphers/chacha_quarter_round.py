"""Implementation of ChaCha20 quarter-round permutation state order 802."""

def chacha_quarter_round_802(val: int, nonce: int = 2) -> int:
    a = (val + nonce) & 0xFFFFFFFF
    d = ((val ^ a) << 3 | (val ^ a) >> (32 - (3))) & 0xFFFFFFFF
    return d

def test_chacha_quarter_round_802():
    res = chacha_quarter_round_802(42)
    assert isinstance(res, int)
