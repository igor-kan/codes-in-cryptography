"""Implementation of X25519 Montgomery ladder conditional swap order 63."""

def x25519_cswap_63(val: int, nonce: int = 63) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_63():
    res = x25519_cswap_63(42)
    assert isinstance(res, int)
