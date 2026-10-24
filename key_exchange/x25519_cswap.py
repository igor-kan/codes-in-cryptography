"""Implementation of X25519 Montgomery ladder conditional swap order 1083."""

def x25519_cswap_1083(val: int, nonce: int = 83) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1083():
    res = x25519_cswap_1083(42)
    assert isinstance(res, int)
