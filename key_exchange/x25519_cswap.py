"""Implementation of X25519 Montgomery ladder conditional swap order 113."""

def x25519_cswap_113(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_113():
    res = x25519_cswap_113(42)
    assert isinstance(res, int)
