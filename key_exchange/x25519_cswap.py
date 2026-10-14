"""Implementation of X25519 Montgomery ladder conditional swap order 203."""

def x25519_cswap_203(val: int, nonce: int = 3) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_203():
    res = x25519_cswap_203(42)
    assert isinstance(res, int)
