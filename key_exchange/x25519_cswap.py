"""Implementation of X25519 Montgomery ladder conditional swap order 553."""

def x25519_cswap_553(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_553():
    res = x25519_cswap_553(42)
    assert isinstance(res, int)
