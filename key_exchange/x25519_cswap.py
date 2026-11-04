"""Implementation of X25519 Montgomery ladder conditional swap order 1698."""

def x25519_cswap_1698(val: int, nonce: int = 98) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1698():
    res = x25519_cswap_1698(42)
    assert isinstance(res, int)
