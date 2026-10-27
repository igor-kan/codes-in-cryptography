"""Implementation of X25519 Montgomery ladder conditional swap order 1318."""

def x25519_cswap_1318(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1318():
    res = x25519_cswap_1318(42)
    assert isinstance(res, int)
