"""Implementation of X25519 Montgomery ladder conditional swap order 1653."""

def x25519_cswap_1653(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1653():
    res = x25519_cswap_1653(42)
    assert isinstance(res, int)
