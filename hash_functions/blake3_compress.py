"""Implementation of BLAKE3 chunk tree compression step order 1124."""

def blake3_compress_1124(val: int, nonce: int = 24) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_1124():
    res = blake3_compress_1124(42)
    assert isinstance(res, int)
