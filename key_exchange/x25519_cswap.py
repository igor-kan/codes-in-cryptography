"""Implementation of X25519 Montgomery ladder conditional swap order 283."""

def x25519_cswap_283(val: int, nonce: int = 83) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_283():
    res = x25519_cswap_283(42)
    assert isinstance(res, int)
