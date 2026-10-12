"""Implementation of X25519 Montgomery ladder conditional swap order 58."""

def x25519_cswap_58(val: int, nonce: int = 58) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_58():
    res = x25519_cswap_58(42)
    assert isinstance(res, int)
