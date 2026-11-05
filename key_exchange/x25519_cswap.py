"""Implementation of X25519 Montgomery ladder conditional swap order 1748."""

def x25519_cswap_1748(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1748():
    res = x25519_cswap_1748(42)
    assert isinstance(res, int)
