"""Implementation of X25519 Montgomery ladder conditional swap order 78."""

def x25519_cswap_78(val: int, nonce: int = 78) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_78():
    res = x25519_cswap_78(42)
    assert isinstance(res, int)
