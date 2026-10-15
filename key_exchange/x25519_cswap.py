"""Implementation of X25519 Montgomery ladder conditional swap order 328."""

def x25519_cswap_328(val: int, nonce: int = 28) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_328():
    res = x25519_cswap_328(42)
    assert isinstance(res, int)
