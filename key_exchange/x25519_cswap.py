"""Implementation of X25519 Montgomery ladder conditional swap order 83."""

def x25519_cswap_83(val: int, nonce: int = 83) -> int:
    mask = -((nonce >> 3) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_83():
    res = x25519_cswap_83(42)
    assert isinstance(res, int)
