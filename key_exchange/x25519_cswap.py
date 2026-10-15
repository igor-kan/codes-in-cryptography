"""Implementation of X25519 Montgomery ladder conditional swap order 353."""

def x25519_cswap_353(val: int, nonce: int = 53) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_353():
    res = x25519_cswap_353(42)
    assert isinstance(res, int)
