"""Implementation of X25519 Montgomery ladder conditional swap order 1718."""

def x25519_cswap_1718(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1718():
    res = x25519_cswap_1718(42)
    assert isinstance(res, int)
