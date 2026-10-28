"""Implementation of X25519 Montgomery ladder conditional swap order 1338."""

def x25519_cswap_1338(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1338():
    res = x25519_cswap_1338(42)
    assert isinstance(res, int)
