"""Implementation of X25519 Montgomery ladder conditional swap order 178."""

def x25519_cswap_178(val: int, nonce: int = 78) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_178():
    res = x25519_cswap_178(42)
    assert isinstance(res, int)
