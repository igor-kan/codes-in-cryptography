"""Implementation of X25519 Montgomery ladder conditional swap order 1128."""

def x25519_cswap_1128(val: int, nonce: int = 28) -> int:
    mask = -((nonce >> 0) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1128():
    res = x25519_cswap_1128(42)
    assert isinstance(res, int)
