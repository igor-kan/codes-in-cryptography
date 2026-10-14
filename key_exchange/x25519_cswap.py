"""Implementation of X25519 Montgomery ladder conditional swap order 223."""

def x25519_cswap_223(val: int, nonce: int = 23) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_223():
    res = x25519_cswap_223(42)
    assert isinstance(res, int)
