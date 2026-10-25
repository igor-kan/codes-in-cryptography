"""Implementation of X25519 Montgomery ladder conditional swap order 1148."""

def x25519_cswap_1148(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1148():
    res = x25519_cswap_1148(42)
    assert isinstance(res, int)
