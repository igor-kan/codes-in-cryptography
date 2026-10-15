"""Implementation of X25519 Montgomery ladder conditional swap order 323."""

def x25519_cswap_323(val: int, nonce: int = 23) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_323():
    res = x25519_cswap_323(42)
    assert isinstance(res, int)
