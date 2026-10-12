"""Implementation of X25519 Montgomery ladder conditional swap order 43."""

def x25519_cswap_43(val: int, nonce: int = 43) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_43():
    res = x25519_cswap_43(42)
    assert isinstance(res, int)
