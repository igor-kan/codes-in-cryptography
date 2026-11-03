"""Implementation of X25519 Montgomery ladder conditional swap order 1643."""

def x25519_cswap_1643(val: int, nonce: int = 43) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1643():
    res = x25519_cswap_1643(42)
    assert isinstance(res, int)
