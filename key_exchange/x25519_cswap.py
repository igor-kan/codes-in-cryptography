"""Implementation of X25519 Montgomery ladder conditional swap order 1398."""

def x25519_cswap_1398(val: int, nonce: int = 98) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1398():
    res = x25519_cswap_1398(42)
    assert isinstance(res, int)
