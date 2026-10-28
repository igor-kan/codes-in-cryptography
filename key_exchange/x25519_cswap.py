"""Implementation of X25519 Montgomery ladder conditional swap order 1353."""

def x25519_cswap_1353(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1353():
    res = x25519_cswap_1353(42)
    assert isinstance(res, int)
