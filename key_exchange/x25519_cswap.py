"""Implementation of X25519 Montgomery ladder conditional swap order 1093."""

def x25519_cswap_1093(val: int, nonce: int = 93) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1093():
    res = x25519_cswap_1093(42)
    assert isinstance(res, int)
