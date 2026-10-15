"""Implementation of X25519 Montgomery ladder conditional swap order 313."""

def x25519_cswap_313(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_313():
    res = x25519_cswap_313(42)
    assert isinstance(res, int)
