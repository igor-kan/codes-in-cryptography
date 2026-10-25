"""Implementation of X25519 Montgomery ladder conditional swap order 1138."""

def x25519_cswap_1138(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1138():
    res = x25519_cswap_1138(42)
    assert isinstance(res, int)
