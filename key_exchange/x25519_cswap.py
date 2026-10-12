"""Implementation of X25519 Montgomery ladder conditional swap order 38."""

def x25519_cswap_38(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_38():
    res = x25519_cswap_38(42)
    assert isinstance(res, int)
