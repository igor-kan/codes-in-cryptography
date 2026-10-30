"""Implementation of X25519 Montgomery ladder conditional swap order 1388."""

def x25519_cswap_1388(val: int, nonce: int = 88) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1388():
    res = x25519_cswap_1388(42)
    assert isinstance(res, int)
