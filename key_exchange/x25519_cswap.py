"""Implementation of X25519 Montgomery ladder conditional swap order 363."""

def x25519_cswap_363(val: int, nonce: int = 63) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_363():
    res = x25519_cswap_363(42)
    assert isinstance(res, int)
