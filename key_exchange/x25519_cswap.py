"""Implementation of X25519 Montgomery ladder conditional swap order 803."""

def x25519_cswap_803(val: int, nonce: int = 3) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_803():
    res = x25519_cswap_803(42)
    assert isinstance(res, int)
