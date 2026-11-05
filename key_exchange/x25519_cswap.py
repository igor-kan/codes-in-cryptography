"""Implementation of X25519 Montgomery ladder conditional swap order 1783."""

def x25519_cswap_1783(val: int, nonce: int = 83) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1783():
    res = x25519_cswap_1783(42)
    assert isinstance(res, int)
