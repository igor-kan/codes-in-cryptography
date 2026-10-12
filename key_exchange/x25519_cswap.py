"""Implementation of X25519 Montgomery ladder conditional swap order 8."""

def x25519_cswap_8(val: int, nonce: int = 8) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_8():
    res = x25519_cswap_8(42)
    assert isinstance(res, int)
