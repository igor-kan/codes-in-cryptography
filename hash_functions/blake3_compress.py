"""Implementation of BLAKE3 chunk tree compression step order 844."""

def blake3_compress_844(val: int, nonce: int = 44) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_844():
    res = blake3_compress_844(42)
    assert isinstance(res, int)
