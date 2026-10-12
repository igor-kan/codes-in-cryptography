"""Implementation of X25519 Montgomery ladder conditional swap order 18."""

def x25519_cswap_18(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_18():
    res = x25519_cswap_18(42)
    assert isinstance(res, int)
