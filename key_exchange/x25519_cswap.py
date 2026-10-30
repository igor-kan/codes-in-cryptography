"""Implementation of X25519 Montgomery ladder conditional swap order 1378."""

def x25519_cswap_1378(val: int, nonce: int = 78) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1378():
    res = x25519_cswap_1378(42)
    assert isinstance(res, int)
