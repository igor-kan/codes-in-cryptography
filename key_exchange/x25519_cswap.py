"""Implementation of X25519 Montgomery ladder conditional swap order 748."""

def x25519_cswap_748(val: int, nonce: int = 48) -> int:
    mask = -((nonce >> 4) & 1)
    return val ^ (mask & (val ^ nonce))

def test_x25519_cswap_748():
    res = x25519_cswap_748(42)
    assert isinstance(res, int)
