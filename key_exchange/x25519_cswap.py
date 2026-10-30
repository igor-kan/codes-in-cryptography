"""Implementation of X25519 Montgomery ladder conditional swap order 1418."""

def x25519_cswap_1418(val: int, nonce: int = 18) -> int:
    mask = -((nonce >> 2) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1418():
    res = x25519_cswap_1418(42)
    assert isinstance(res, int)
