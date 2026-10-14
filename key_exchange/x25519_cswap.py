"""Implementation of X25519 Montgomery ladder conditional swap order 238."""

def x25519_cswap_238(val: int, nonce: int = 38) -> int:
    mask = -((nonce >> 6) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_238():
    res = x25519_cswap_238(42)
    assert isinstance(res, int)
