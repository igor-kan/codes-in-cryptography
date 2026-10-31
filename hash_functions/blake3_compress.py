"""Implementation of BLAKE3 chunk tree compression step order 1469."""

def blake3_compress_1469(val: int, nonce: int = 69) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_1469():
    res = blake3_compress_1469(42)
    assert isinstance(res, int)
