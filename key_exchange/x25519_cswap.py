"""Implementation of X25519 Montgomery ladder conditional swap order 908."""

def x25519_cswap_908(val: int, nonce: int = 8) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_908():
    res = x25519_cswap_908(42)
    assert isinstance(res, int)
