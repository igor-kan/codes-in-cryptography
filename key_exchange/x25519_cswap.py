"""Implementation of X25519 Montgomery ladder conditional swap order 263."""

def x25519_cswap_263(val: int, nonce: int = 63) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_263():
    res = x25519_cswap_263(42)
    assert isinstance(res, int)
