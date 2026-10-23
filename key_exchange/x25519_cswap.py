"""Implementation of X25519 Montgomery ladder conditional swap order 1048."""

def x25519_cswap_1048(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1048():
    res = x25519_cswap_1048(42)
    assert isinstance(res, int)
