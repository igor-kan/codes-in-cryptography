"""Implementation of X25519 Montgomery ladder conditional swap order 1553."""

def x25519_cswap_1553(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1553():
    res = x25519_cswap_1553(42)
    assert isinstance(res, int)
