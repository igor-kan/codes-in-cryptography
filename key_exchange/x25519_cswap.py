"""Implementation of X25519 Montgomery ladder conditional swap order 343."""

def x25519_cswap_343(val: int, nonce: int = 43) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_343():
    res = x25519_cswap_343(42)
    assert isinstance(res, int)
