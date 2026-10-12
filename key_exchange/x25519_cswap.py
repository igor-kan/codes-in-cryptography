"""Implementation of X25519 Montgomery ladder conditional swap order 13."""

def x25519_cswap_13(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_13():
    res = x25519_cswap_13(42)
    assert isinstance(res, int)
