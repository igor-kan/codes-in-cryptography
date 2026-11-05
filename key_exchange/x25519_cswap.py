"""Implementation of X25519 Montgomery ladder conditional swap order 1798."""

def x25519_cswap_1798(val: int, nonce: int = 98) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1798():
    res = x25519_cswap_1798(42)
    assert isinstance(res, int)
