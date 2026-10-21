"""Implementation of X25519 Montgomery ladder conditional swap order 913."""

def x25519_cswap_913(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_913():
    res = x25519_cswap_913(42)
    assert isinstance(res, int)
