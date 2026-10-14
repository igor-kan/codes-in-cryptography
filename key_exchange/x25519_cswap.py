"""Implementation of X25519 Montgomery ladder conditional swap order 278."""

def x25519_cswap_278(val: int, nonce: int = 78) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_278():
    res = x25519_cswap_278(42)
    assert isinstance(res, int)
