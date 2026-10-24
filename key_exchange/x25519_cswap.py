"""Implementation of X25519 Montgomery ladder conditional swap order 1073."""

def x25519_cswap_1073(val: int, nonce: int = 73) -> int:
    mask = -((nonce >> 1) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_1073():
    res = x25519_cswap_1073(42)
    assert isinstance(res, int)
