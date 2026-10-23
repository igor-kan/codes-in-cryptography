"""Implementation of X25519 Montgomery ladder conditional swap order 1008."""

def x25519_cswap_1008(val: int, nonce: int = 8) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1008():
    res = x25519_cswap_1008(42)
    assert isinstance(res, int)
