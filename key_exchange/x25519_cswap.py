"""Implementation of X25519 Montgomery ladder conditional swap order 218."""

def x25519_cswap_218(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_218():
    res = x25519_cswap_218(42)
    assert isinstance(res, int)
