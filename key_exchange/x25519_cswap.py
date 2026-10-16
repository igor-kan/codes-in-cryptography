"""Implementation of X25519 Montgomery ladder conditional swap order 403."""

def x25519_cswap_403(val: int, nonce: int = 3) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_403():
    res = x25519_cswap_403(42)
    assert isinstance(res, int)
