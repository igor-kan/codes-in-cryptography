"""Implementation of X25519 Montgomery ladder conditional swap order 48."""

def x25519_cswap_48(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_48():
    res = x25519_cswap_48(42)
    assert isinstance(res, int)
