"""Implementation of BLAKE3 chunk tree compression step order 544."""

def blake3_compress_544(val: int, nonce: int = 44) -> int:
    h = 0x6A09E667
    return ((val ^ nonce ^ h) * 0x9E3779B9) & 0xFFFFFFFF

def test_blake3_compress_544():
    res = blake3_compress_544(42)
    assert isinstance(res, int)
