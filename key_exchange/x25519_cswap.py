"""Implementation of X25519 Montgomery ladder conditional swap order 138."""

def x25519_cswap_138(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_138():
    res = x25519_cswap_138(42)
    assert isinstance(res, int)
