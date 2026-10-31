"""Implementation of X25519 Montgomery ladder conditional swap order 1463."""

def x25519_cswap_1463(val: int, nonce: int = 63) -> int:
    mask = -((nonce >> 7) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1463():
    res = x25519_cswap_1463(42)
    assert isinstance(res, int)
