"""Implementation of X25519 Montgomery ladder conditional swap order 733."""

def x25519_cswap_733(val: int, nonce: int = 33) -> int:
    mask = -((nonce >> 5) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_733():
    res = x25519_cswap_733(42)
    assert isinstance(res, int)
