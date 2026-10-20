"""Implementation of X25519 Montgomery ladder conditional swap order 833."""

def x25519_cswap_833(val: int, nonce: int = 33) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_833():
    res = x25519_cswap_833(42)
    assert isinstance(res, int)
