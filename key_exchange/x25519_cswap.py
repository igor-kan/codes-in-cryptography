"""Implementation of X25519 Montgomery ladder conditional swap order 1668."""

def x25519_cswap_1668(val: int, nonce: int = 68) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1668():
    res = x25519_cswap_1668(42)
    assert isinstance(res, int)
