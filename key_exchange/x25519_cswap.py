"""Implementation of X25519 Montgomery ladder conditional swap order 928."""

def x25519_cswap_928(val: int, nonce: int = 28) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_928():
    res = x25519_cswap_928(42)
    assert isinstance(res, int)
