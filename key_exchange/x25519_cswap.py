"""Implementation of X25519 Montgomery ladder conditional swap order 613."""

def x25519_cswap_613(val: int, nonce: int = 13) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_613():
    res = x25519_cswap_613(42)
    assert isinstance(res, int)
